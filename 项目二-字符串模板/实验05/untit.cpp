//#include<bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
class cstring
{
   friend ostream & operator<<(ostream & out,cstring &pn);
   friend istream & operator>>(istream & cin,cstring &pn);
  // friend cstring operator+(cstring & pn);
public:
    cstring (const char *pName = "N")
    {
        str = new char [strlen(pName)+1];
        strcpy(str,pName);
    }
    cstring (const cstring &pn)
    {
        str = new char [strlen(pn.str)+1];
        strcpy(str,pn.str);
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
    //重载+
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
private:
    char *str;
};
//重载<<
ostream & operator<<(ostream & cout,cstring &pn)
{
    int i;
    for(i=0;i<strlen(pn.str);i++)
        cout<<*(pn.str+i);
    return cout; 
}
//重载>>
istream & operator>>(istream & cin,cstring &pn)
{
    int i=0;
    // for(i=0;i<strlen(pn.str)+1;i++)
    //     *(pn.str+i)=0;
    
    // i=0;
    while((*(pn.str+i)=getchar())!='\n')
        {
            i++;
        }
    *(pn.str+i)='\0';
    return cin;
}

void test()
{
    cstring p1;
    cstring p2;
}
int main()
{
    test();
    return 0;
}
