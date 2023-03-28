#include<bits/stdc++.h>
#include "cstring.h"
using namespace std;
   cstring::cstring (const char *s)
    {
        str = new char [strlen(s)+1];
        strcpy(str,s);
    }
   cstring::cstring (const char *s,int n)
    {
        int i, m = strlen(s);
        if (m<n) n=m;
        if (n<0) n=0;
        str = new char [n+1];
        for (i=0;i<n;i++)
            str[i] = s[i];
        str[i] = '\0';
    }
    cstring::cstring (int n,char c)
    {
        int i;
        if (n<0) n=0;
        str = new char [n+1];
        for (i=0;i<n;i++)
            str[i] = c;
        str[i] = '\0';
    }
    cstring::cstring (const cstring &pn)
    {
        str = new char [strlen(pn.str)+1];
        strcpy(str,pn.str);
    }
    cstring::cstring (const cstring &pn,int pos ,int n)
    {
        int i,m;
        m = strlen(pn.str);
        if (pos>m)
        {
            str = new char[1];
            str[0] = '\0';
            return;
        }
        if ((m-pos)< n) n = m-pos ;
        if (n<0) n = 0;
        str = new char[n+1];
        for (i=0;i<n;i++)
            str[i] = pn.str[pos+i];
        str[i] = '\0';
    }
   cstring & cstring::operator=(const cstring &pn)
    {
        if (&pn==this) return *this;
        delete [] str;
        str = new char[strlen(pn.str)+1];
        strcpy(str,pn.str);
        return *this;
    }
    cstring::~cstring()
    {
        if (str!=NULL) delete [] str;
    }
    ostream & operator<<(ostream &out,const cstring &pn)
    {
        out << pn.str;
        return out;
    }
    istream & operator>>(istream &in,cstring &pn)
    {
        char str[1000];
        in >> str;
        pn = str;
        return in;
    }
    istream & getline(istream &in,cstring &pn,int num,char delim)throw(char)
    {
        char a = 'c';
		if (num<=0) return in;
        if (pn.str!=NULL) delete [] pn.str;
        pn.str = new char [num+1];
        in.getline(pn.str,num,delim);
		if(pn.str[0]==NULL||pn.str[0]=='\0')throw(char)a;
        return in;
    }
    cstring & cstring::trim()
    {
        int i,j = strlen(str);
        if (j==0) return *this;
        for (j--;j>=0&&(str[j]==' '||str[j]=='\t');j--)
            ;
        str[j+1] = '\0';
        for (i=0;str[i]==' '||str[i]=='\t';i++)
            ;
        if (i<j)
        {
            delete [] str;
            str = new char [1];
            str[0] = '\0';
        }
        else
        {
            char *temp = new char [j-i+2];
            strcpy(temp,str+i);
            delete [] str;
            str = temp;
        }
        return *this;
    }
  cstring operator+(const cstring &pn1,const cstring &pn2)
    {
        cstring temp;
        temp.str = new char[strlen(pn1.str)+strlen(pn2.str)+1];
        strcpy(temp.str,pn1.str);
        strcat(temp.str,pn2.str);
        return temp;
    }
    //重载>
  bool operator>(const cstring &pn1,const cstring &pn2)
    {
        return strcmp(pn1.str,pn2.str) > 0;
    }
    //重载>=
   bool operator>=(const cstring &pn1,const cstring &pn2)
    {
        return strcmp(pn1.str,pn2.str) >= 0;
    }
    //重载<
  bool operator<(const cstring &pn1,const cstring &pn2)
    {
        return strcmp(pn1.str,pn2.str) < 0;
    }
    //重载<=
  bool operator<=(const cstring &pn1,const cstring &pn2)
    {
       return strcmp(pn1.str,pn2.str) <= 0;
    }
    //重载==
   bool operator==(const cstring &pn1,const cstring &pn2)
    {
        return strcmp(pn1.str,pn2.str) == 0;
    }
    //重载!=
   bool operator!=(const cstring &pn1,const cstring &pn2)
    {
        return strcmp(pn1.str,pn2.str) != 0;
    }
    //重载+=
   cstring & cstring::operator+=(const cstring &pn)
    {
        *this = *this + pn;
        return *this;
    }

    char &cstring::operator[](int i)throw(int)
    {
        int n;
		n=strlen(str);
		if(i>=n)throw(int)i;
        return str[i];
    }
    int cstring::length() const
    {
        return strlen(str);
    }
    const char* cstring::c_str()
    {
        return str;
    }
    void cstring::swap(cstring &cstr)
    {
        char*temp = cstr.str;
        cstr.str = str;
        str = temp;
    }

