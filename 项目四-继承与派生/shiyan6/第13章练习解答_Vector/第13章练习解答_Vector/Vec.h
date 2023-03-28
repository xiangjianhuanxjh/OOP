// Vec.h
#ifndef VEC_H
#define VEC_H
#include <iostream>
using namespace std;

template <typename T> class VECTOR			
{
public:
	VECTOR(int size=0, const T *x=NULL);	
	VECTOR(const VECTOR &v);				
	virtual ~VECTOR();						
	VECTOR & operator=(const VECTOR &v);	
	T & operator[](int index) const throw(int);
	int getsize() const;					
	void resize(int size);					

	virtual void Output(ostream &out) const = 0;
	virtual void Input(istream &in) = 0;		

protected:								
	int num;									
	T *p;										
};

template <typename T>
VECTOR<T>::VECTOR(int size, const T *x)	
{
	num = (size>0) ? size : 0;
	p = NULL;
	if(num>0)
	{
		p = new T[num];
		for(int i=0; i<num; i++)
			p[i] = (x==NULL)? 0 : x[i];
	}
}

template <typename T>
VECTOR<T>::VECTOR(const VECTOR<T> &v)	
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
VECTOR<T>::~VECTOR()						
{
	num = 0;
	if(p!=NULL) delete [] p;
}

template <typename T>
VECTOR<T> & VECTOR<T>::operator=(const VECTOR<T> &v)
{
	if(num!=v.num)
	{
		if(p!=NULL) delete [] p;
		p = new T[num=v.num];
	}
	for(int i=0; i<num; i++)
		p[i] = v.p[i];
	return *this;
}

template <typename T>
T & VECTOR<T>::operator[](int index) const throw(int)
{
	if(p==NULL)
		throw 0;							
	if(index<0 || index>=num)
		throw -1;
	return p[index];
}

template <typename T>
int VECTOR<T>::getsize() const				
{
	return num;
}

template <typename T>
void VECTOR<T>::resize(int size)			
{
	if(size<0 || size==num)
		return;
	else if(size==0)
	{
		if(p!=NULL) delete [] p;
		p = NULL;
		num = 0;
	}
	else
	{
		T *temp = p;
		p = new T[size];
		for(int i=0; i<size; i++)
			p[i] = (i<num) ? temp[i] : 0;	
		num = size;
		delete [] temp;	
	}
}

template <typename T>
ostream & operator<<(ostream &out, const VECTOR<T> &v)	
{
	v.Output(out);
	return out;
}

template <typename T>
istream & operator>>(istream &in, VECTOR<T> &v)			
{
	v.Input(in);
	return in;
}

#endif
