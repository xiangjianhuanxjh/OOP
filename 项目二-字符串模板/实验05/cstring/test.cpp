#include "cstring.h"
#include <bits/stdc++.h>
using namespace std;
int test1()
{
    cout<<"��������+�Լ��Ĵ�������"<<endl;
    cstring pn1 = "Hello", pn2 = pn1,pn3;
    cout<<"������ַ�����"<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
    pn3 = pn2;
    cout<<"��ֵƴ�Ӹı�֮��"<<endl;
    pn1 = "C++ program.";
    pn2 = pn3 + ", world!";
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
    cout<<"����[]����"<<endl;
    cout<< &(pn1[0]) <<endl;
    cout<<"����getline�Ĺ���"<<endl;
    getline(cin,pn1,80);
    cout<<"\""<<pn1<<"\""<<endl;
    return 0;
}
int test2()
{
    cout<<"���ԱȽ�������Ĺ���"<<endl;
    cstring pn1 = "qwer",pn2 = "qwert",pn3 = "qwe",pn4 = "qwer";
    cout<<"������ַ�����"<<endl;
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
    cout<<"���Լ��㺯���Ĺ���"<<endl;
    cstring pn1 = "qwer",pn2 = "qwert",pn3 = "qwerty";
    cout<<"������ַ�����"<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
   length = pn1.length();
   s1 = pn2.c_str();
   pn1.swap(pn2);
   s2 = pn2.c_str();
   cout<<"�ַ���pn1�ĳ�����:"<<length<<endl;
   cout<<"�ַ���pn2Ϊ��"<<s1<<endl;
   cout<<"�ַ���pn2��pn1������pn2Ϊ:"<<s2<<" pn1Ϊ:"<<s1<<endl;
   return 0;
}
int test4()
{
    int x;
    cstring pn1 = "qwer",pn2 = "qwert",pn3 = "qwerty";
    cout<<"�±�������ѹ��ܵĲ���:"<<endl;
    cout<<"������ַ�����"<<endl;
    cout<<"pn1 = \""<<pn1
    <<"\"\npn2 = \""<<pn2
    <<"\"\npn3 = \""<<pn3<<"\""<<endl;
    try
    {
        cin>>x;
        cout<<"�ַ����ĵ�"<<x<<"λΪ�ַ���"<<pn1[x-1]<<endl;
    }
    catch(int)
    {
        cout<<"�±귢��Խ�磬�޷���ʾ!"<<endl;
    }
    return 0;
}
int test5()
{
    cstring pn1 = "";
    cout<<"����������ѹ��ܵĲ���:"<<endl;
    try
    {
        getline(cin,pn1,50);
        cout<<pn1<<endl;
    }
    catch(char)
    {
        cout<<"����Ϊ�գ�"<<endl;
    }
    return 0;
}
