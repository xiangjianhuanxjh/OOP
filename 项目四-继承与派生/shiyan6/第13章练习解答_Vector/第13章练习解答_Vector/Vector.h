// Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include "Vec.h"

template <typename T> class Vector : public VECTOR<T>
{
public:
	Vector(int size=0, const T *x=NULL);

	void Input(istream &in);
	void Output(ostream &out) const;
	template <typename TYPE> friend Vector<TYPE> operator+(const Vector<TYPE> &v1, const Vector<TYPE> &v2) throw(double);
	template <typename TYPE> friend Vector<TYPE> operator-(const Vector<TYPE> &v1, const Vector<TYPE> &v2) throw(double);
	template <typename TYPE> friend Vector<TYPE> operator*(const T &x, const Vector<TYPE> &v);
	template <typename TYPE> friend Vector<TYPE> operator*(const Vector<TYPE> &v, const T &x);
	Vector<T> & operator+=(const Vector<T> &v) throw(double);
	Vector<T> & operator-=(const Vector<T> &v) throw(double);
};

template <typename T>
Vector<T>::Vector(int size, const T *x) : VECTOR<T>(size, x)		
{
}

template <typename T>
void Vector<T>::Output(ostream &out) const
{
	if(this->num==0)
		out << "()";
	else
	{
		out << "(" << this->p[0];
		for(int i=1; i<this->num; i++)
			out << ", " << this->p[i];
		out << ")";
	}
}

template <typename T>
void Vector<T>::Input(istream &in)	
{
	const int M=1024, N = 1;
	Vector<T> temp;
	char str[M], ch;				
	T buffer[N];
	int i, j, k;

	in.getline(str, M, '(');		
	while(true)						
	{
		ch = in.peek();				
		if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\r')
			in.get(ch);				
		else
			break;					
	}

	if(in.peek()==')')				
	{
		this->resize(0);			
		return;						
	}

	for(k=0; ch!=')'; k++)
	{
		for(i=0; i<N && ch!=')'; i++)
			in >> buffer[i] >> ch;
		temp.resize(k*N+i);			
		for(j=0; j<i; j++)
			temp[k*N+j] = buffer[j];
	}
	*this = temp;					
}

template <typename T>
Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2) throw(double)
{
	if(v1.getsize() != v2.getsize())
		throw -1.0;					
	Vector<T> result(v1);
	for(int i=v1.getsize()-1; i>=0; i--)
		result[i] += v2[i];			
	return result;
}

template <typename T>
Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2) throw(double)
{
	if(v1.getsize() != v2.getsize())
		throw -1.0;					
	Vector<T> result(v1);
	for(int i=v1.getsize()-1; i>=0; i--)
		result[i] -= v2[i];			
	return result;
}

template <typename T>
Vector<T> operator*(const T &x, const Vector<T> &v)
{
	Vector<T> result(v);
	for(int i=v.getsize()-1; i>=0; i--)
		result[i] = x*v[i];
	return result;
}

template <typename T>
Vector<T> operator*(const Vector<T> &v, const T &x)
{
	return x*v;
}

template <typename T>
Vector<T> & Vector<T>::operator+=(const Vector<T> &v) throw(double)
{
	return *this = *this + v;
}

template <typename T>
Vector<T> & Vector<T>::operator-=(const Vector<T> &v) throw(double)
{
	return *this = *this - v;
}


#endif
