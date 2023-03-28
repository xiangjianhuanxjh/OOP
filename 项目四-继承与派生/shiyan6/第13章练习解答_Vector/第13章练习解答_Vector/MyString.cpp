// MyString.cpp
#include "MyString.h"
#include <cstring>

String::String(const char *str) : VECTOR<char>(strlen(str), str)	
{
}

int String::length() const
{
	return num;			
}

void String::Output(ostream &out) const
{
	for(int i=0; i<num; i++)
		out << p[i];
}

void String::Input(istream &in)
{
	const int N = 1;
	char buffer[N], ch;			
	int i, j, k, flag;
	String temp;
	
	while(true)					
	{
		ch = in.peek();			
		if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\r')
			in.get(ch);			
		else
			break;				
	}
	for(k=0,flag=1; flag==1; k++)
	{
		for(i=0; i<N; i++)
		{
			ch = in.peek();
			if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\r')
			{
				flag = 0;
				break;
			}
			else
				in.get(buffer[i]);
		}
		temp.resize(k*N+i);			
		for(j=0; j<i; j++)
			temp[k*N+j] = buffer[j];
	}
	*this = temp;					
}

istream & getline(istream &in, String &Str, int n, char delim)
{
	if(n<=0) return in;
	char *p = new char[n];
	in.getline(p, n, delim);
	Str = p;			
	delete [] p;
	return in;
}

String operator+(const String &s1, const String &s2)
{
	String result(s1);
	int n1 = s1.length(), n2 = s2.length();
	result.resize(n1 + n2);
	for(int i=0; i<n2; i++)
		result[n1+i] = s2[i];
	return result;
}

String & String::operator+=(const String &s)
{
	resize(num + s.num);
	for(int i=0; i<s.num; i++)
		p[num+i] = s.p[i];
	return *this;
}

bool operator<(const String &s1, const String &s2)
{
	int i, n1=s1.length(), n2=s2.length();
	for(i=0; i<n1 && i<n2 && s1[i]==s2[i]; i++)
		;
	if(i<n1 && i<n2)
		return (unsigned char)s1[i] < (unsigned char)s2[i];
	else if(i<n1 && i==n2)
		return false;
	else if(i==n1 && i<n2)
		return true;
	else
		return false;
}

bool operator<=(const String &s1, const String &s2)
{
	int i, n1=s1.length(), n2=s2.length();
	for(i=0; i<n1 && i<n2 && s1[i]==s2[i]; i++)
		;
	if(i<n1 && i<n2)
		return (unsigned char)s1[i] < (unsigned char)s2[i];
	else if(i<n1 && i==n2)
		return false;
	else
		return true;
}

bool operator>(const String &s1, const String &s2)
{
	return !(s1<=s2);
}

bool operator>=(const String &s1, const String &s2)
{
	return !(s1<s2);
}

bool operator==(const String &s1, const String &s2)
{
	int i, n1=s1.length(), n2=s2.length();
	for(i=0; i<n1 && i<n2 && s1[i]==s2[i]; i++)
		;
	if(i<n1 || i<n2)
		return false;
	else
		return true;
}

bool operator!=(const String &s1, const String &s2)
{
	return !(s1==s2);
}
