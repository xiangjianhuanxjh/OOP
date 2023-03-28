#ifndef MY_CSTRING_H
#define MY_CSTRING_H
#include<bits/stdc++.h>
using namespace std;
class cstring
{
public:
    cstring (const char *s="");
    cstring (const char *s,int n);
    cstring (int n,char c);
    cstring (const cstring &pn);
    cstring (const cstring &pn,int pos ,int n);
    cstring & operator=(const cstring &pn);
    ~cstring();
    friend ostream& operator<<(ostream &out,const cstring &pn);
    friend istream & operator>>(istream &in,cstring &pn);
    friend istream & getline(istream &in,cstring &pn,int num,char delim='\n')throw(char);
    cstring &trim();
    friend  cstring operator+(const cstring &pn1,const cstring &pn2);
    //重载>
    friend  bool operator>(const cstring &pn1,const cstring &pn2);
    //重载>=
    friend bool operator>=(const cstring &pn1,const cstring &pn2);
    //重载<
    friend  bool operator<(const cstring &pn1,const cstring &pn2);
    //重载<=
    friend  bool operator<=(const cstring &pn1,const cstring &pn2);
    //重载==
    friend bool operator==(const cstring &pn1,const cstring &pn2);
    //重载!=
    friend bool operator!=(const cstring &pn1,const cstring &pn2);
    //重载+=
    cstring & operator+=(const cstring &pn);
    char &operator[](int i)throw(int);
    int length() const;
    const char* c_str();
    void swap(cstring &cstr);
private:
    char *str;
};
#endif


