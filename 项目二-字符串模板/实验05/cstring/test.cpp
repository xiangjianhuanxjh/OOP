#include "cstring.h"
#include <bits/stdc++.h>
using namespace std;
int test1()
{
    cout<<"测试重载+以及四大函数功能"<<endl;
    cstring pn1 = "Hello", pn2 = pn1,pn3;
    cout<<"最初的字符串："<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
    pn3 = pn2;
    cout<<"赋值拼接改变之后"<<endl;
    pn1 = "C++ program.";
    pn2 = pn3 + ", world!";
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
    cout<<"测试[]重载"<<endl;
    cout<< &(pn1[0]) <<endl;
    cout<<"测试getline的功能"<<endl;
    getline(cin,pn1,80);
    cout<<"\""<<pn1<<"\""<<endl;
    return 0;
}
int test2()
{
    cout<<"测试比较运算符的功能"<<endl;
    cstring pn1 = "qwer",pn2 = "qwert",pn3 = "qwe",pn4 = "qwer";
    cout<<"最初的字符串："<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3
    <<"\"\npn4 = \""<<pn4<<"\""<<endl;
    if (pn1<pn2)
        cout<<"pn1<pn2"<<endl;
    if (pn2>pn3)
        cout<<"pn2>pn3"<<endl;
    if (pn1==pn4)
        cout<<"pn1=pn4"<<endl;
    return 0;
}
int test3()
{
    int length;
    string s1,s2;
    cout<<"测试计算函数的功能"<<endl;
    cstring pn1 = "qwer",pn2 = "qwert",pn3 = "qwerty";
    cout<<"最初的字符串："<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
   length = pn1.length();
   s1 = pn2.c_str();
   pn1.swap(pn2);
   s2 = pn2.c_str();
   cout<<"字符串pn1的长度是:"<<length<<endl;
   cout<<"字符串pn2为："<<s1<<endl;
   cout<<"字符串pn2与pn1交换后，pn2为:"<<s2<<" pn1为:"<<s1<<endl;
   return 0;
}
int test4()
{
    int x;
    cstring pn1 = "qwer",pn2 = "qwert",pn3 = "qwerty";
    cout<<"下标错误提醒功能的测试:"<<endl;
    cout<<"最初的字符串："<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
    try
    {
        cin>>x;
        cout<<"字符串的第"<<x<<"位为字符："<<pn1[x-1]<<endl;
    }
    catch(int)
    {
        cout<<"下标发生越界，无法显示!"<<endl;
    }
    return 0;
}
int test5()
{
    cstring pn1 = "";
    cout<<"输入错误提醒功能的测试:"<<endl;
    try
    {
        getline(cin,pn1,50);
        cout<<pn1<<endl;
    }
    catch(char)
    {
        cout<<"输入为空！"<<endl;
    }
    return 0;
}
