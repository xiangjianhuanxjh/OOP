#ifndef MY_CSTRING_H
#define MY_CSTRING_H
#include<bits/stdc++.h>
using namespace std;
class cstring
{
public:
    cstring (const char *pName = "NoName")
    {
        str = new char [strlen(pName)+1];
        strcpy(str,pName);
    }
    cstring (const char *s,int n)
    {
        int i, m = strlen(s);
        if (m<n) n=m;
        if (n<0) n=0;
        str = new char [n+1];
        for (i=0;i<n;i++)
            str[i] = s[i];
        str[i] = '\0';
    }
    cstring (int n,char c)
    {
        int i;
        if (n<0) n=0;
        str = new char [n+1];
        for (i=0;i<n;i++)
            str[i] = c;
        str[i] = '\0';
    }
    cstring (const cstring &pn)
    {
        str = new char [strlen(pName)+1];
        strcpy(str,pn.str);
    }
    cstring (const cstring &pn,int pos ,int n)
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
    cstring & operator=(const cstring &pn)
    {
        if (&pn==this) return *this;
        delete [] str;
        str = new char[strlen(pn.str)+1];
        strcpy(str,pn.str);
        return *this;
    }
    ~cstring()
    {
        if (str!=NULL) delete [] str;
    }
    friend ostream &operator<<(ostream &out,const cstring &pn)
    {
        out << pn.str;
        return out;
    }
    friend &operator>>(istream &in,cstring &pn)
    {
        char str[1000];
        in >> str;
        pn = str;
        return in;
    }
    friend &getline(istream &in,cstring &pn,int num,char delim)throw(char)
    {
		if (num<=0) return in;
        if (pn.str!=NULL) delete [] pn.str;
        pn.str = new char [num+1];
        in.getline(pn.str,num,delim);
		if(pn.str[0]==NULL||pn,str[0]=='/0')throw(char*)pn.str;
        return in;
    }
    cstring &trim()
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
    cstring & operator+(cstring & pn)
    {
        int i=strlen(this->str);
        strcpy(this->str+i,pn.str);
        return *this;
    }
    //重载>
    bool operator>(cstring &p2)
    {
        int i=strlen(this->str);
        int j=strlen(p2.str);
        if(i>j)
            return true;
        else
            return false;
    }
    //重载>=
    bool operator>=(cstring &p2)
    {
        int i=strlen(this->str);
        int j=strlen(p2.str);
        if((i>j )|| (i=j))
            return true;
        else
            return false;
    }
    //重载<
    bool operator<(cstring &p2)
    {
        int i=strlen(this->str);
        int j=strlen(p2.str);
        if(i<j)
            return true;
        else
            return false;
    }
    //重载<=
    bool operator<=(cstring &p2)
    {
        int i=strlen(this->str);
        int j=strlen(p2.str);
        if((i<j )|| (i=j))
            return true;
        else
            return false;
    }
    //重载==
    bool operator==(cstring &p2)
    {
        int i=strlen(this->str);
        int j=strlen(p2.str);
        if(i==j)
            return true;
        else
            return false;
    }
    //重载!=
    bool operator!=(cstring &p2)
    {
        int i=strlen(this->str);
        int j=strlen(p2.str);
        if(i!=j)
            return true;
        else
            return false;
    }
    //重载+=
    void operator+=(cstring &pn)
    {
        int i=strlen(this->str);
        strcpy(this->str+i,pn.str);
    }
	
	    char operator[](int i)throw(int)
    {
        int n;
		n=strlen(str);
		if(i>=n)throw(int)i;
		char s=*(this->str+i);
        return s;
    }
	
	void testing(int n)
	{
		try 
			{operator[](n);}
		catch(int)
		{
			cout<<"\t 下标越界."<<endl;
		}
	}
	
	void testinput()
	{
		try
		{
			getline(cin,pn.str,50);
		}
		catch(char*0
		{
			cout<<"\t 输出不得为空."<<endl;
			
		}
		
		
		
		
	}
	
    
private:
    char *str;
};
#endif

