#include<iostream>
#include<string>
using namespace std;
template <class F>
class Vector
{

    friend istream& operator>> (istream& cin, Vector<F>& Vec)                                       //����>>
    {
        int n, i;
        cout << "����������ά����";
        cin >> n;
        Vec.v_Weishu = n;
        F fenliang;
        Vec.ChangeWeishu(n);
        
        if (n == 0)
        {
            Vec.Fenliang[0] = 0;
            cout << "��������һ��0����"<<endl;
        }    
        else
        {  
            cout << "��������������������";
            for (i = 0; i < n; i++)
            {
                cin >> fenliang;
                Vec.Fenliang[i] = fenliang;
            }
        }
        return cin;
    }
    friend ostream& operator<<(ostream& cout, Vector<F>& Vec)                                       //����<<
    {

       // cout << "����ά����" << Vec.v_Weishu << endl;
        int i;
        if (Vec.v_Weishu == 0)
            cout << "0����";
        else
        {
            cout << '(';
            for (i = 0; i < Vec.v_Weishu; i++)
            {
                cout << Vec.Fenliang[i];
                if (i != Vec.v_Weishu - 1) cout << ',';
            }
            cout << ')';
        }
        return cout;
    }  
public:
    void ChangeWeishu(int i);                                                                       //�������ź���
    F GetMaxFenliang()const;                                                                        //��ȡ������
    int GetMax() const;                                                                             //������λ��
    int GetWeishu()const;                                                                           //��ȡά������
    F GetSpecificFenliang(int i)const;                                                              //��ȡ�����������
    Vector();                                                                                       //Ĭ�Ϲ��캯��
    Vector(int i,F *a);                                                                             //�вι��캯��
    Vector(int i);
    Vector( const Vector<F>& vec);                                                                  //�������캯��                       
    ~Vector();                                                                                       //��������
    Vector& operator= (const Vector<F>& Vec);                                                       //��ֵ�����"="����
    template<typename T, typename W>
    friend bool operator == (const Vector<T>& Vec1, const Vector<W>& Vec2);                         //����"=="
    template<typename A, typename B>
    friend bool operator != (const Vector<A>& Vec1, const Vector<B>& Vec2);                          //����"!="
    F& operator [](int index);                                                                       //����"[ ]"
    //-------
	template<class F>
    friend Vector<F> operator+(const Vector<F>& Vec1, const Vector<F>& Vec2)throw(int, double);
    Vector& operator+=(const Vector<F>& Vec)throw(char, double);
private:
    int v_Weishu;
    F* Fenliang;
};
template<class F>
void Vector<F>::ChangeWeishu(int i)
{
    v_Weishu = i;
    delete[]Fenliang;
    if (i == 0) Fenliang = new F[1];
        else Fenliang = new F[i];
    int j;
    for (j = 0; j < i; j++)
    {
        Fenliang[j] = 0;
    }
}
template<class F>
Vector<F>::Vector()                                                                                //Ĭ�Ϲ��캯��
{
    v_Weishu = 0;
    Fenliang = NULL;
}
template<class F>
Vector<F>::~Vector()                                                                                //��������
{
    if (Fenliang != NULL)
    {
        delete[]Fenliang;
        Fenliang = NULL;
    }
}
template<class F>
F Vector<F>::GetMaxFenliang() const                                                                 //��ȡ������
{
    int i = 0;
    F max = 0;
    int n = 0;
    for (i = 0; i < v_Weishu; i++)
    {
        if (Fenliang[i] > max)
        {
            max = Fenliang[i];
            n = i + 1;
        }
    }
    return Fenliang[n - 1];
}
template<class F>
int Vector<F>::GetMax() const                                                                       //��ȡ������λ��
{
    int i = 0;
    F max = 0;
    int n = 0;
    for (i = 0; i < v_Weishu; i++)
    {
        if (Fenliang[i] > max)
        {
            max = Fenliang[i];
            n = i + 1;
        }
    }
    return n;
}

template <class F>
int Vector<F>:: GetWeishu()const                                                                    //��ȡά��
{
    return v_Weishu;
}
template<class F>
F Vector<F>::GetSpecificFenliang(int i)const                                                        //��ȡ�������
{
    return Fenliang[i];
}
template<class F>
Vector<F>::Vector(int i, F* a)                                                                      //�вι���
{
    v_Weishu = i;
    int j;
    Fenliang = new F[i];

    for (j = 0; j < i; j++)
    {
        Fenliang[j] =(a[j]);
    }
}
template<class F>
Vector<F>& Vector<F>:: operator=  (const Vector<F>& Vec)                                            //���ء�=��
{
    //v_Weishu = Vec.GetWeishu();
    int i;
    for (i = 0; i < v_Weishu; i++)
    {
        Fenliang[i] = Vec.GetSpecificFenliang(i);
    }
    return *this;
}
template<class F>
Vector<F>::Vector(const Vector<F>& vec)                                                             //�������캯��                                                  
{
    int n = vec.GetWeishu();
    Fenliang = new F[n];
    v_Weishu = vec.GetWeishu();
    int i;
    for (i = 0; i < v_Weishu; i++)
    {
        Fenliang[i] = vec.GetSpecificFenliang(i);
    }
}
template<typename T,typename W>
bool operator == (const Vector<T>& Vec1, const Vector<W>& Vec2)                                     //���ء�==��
{
    int x;
    if (Vec1.v_Weishu != Vec2.v_Weishu)
    {
        return 0;
    }
    x = Vec1.v_Weishu;
    for (int i = 0; i < x; i++)
    {
        if (Vec1.Fenliang[i] != Vec2.Fenliang[i])
        {
            return 0;
        }
    }
    return 1;
}

template<typename A,typename B>
bool operator != (const Vector<A>& Vec1, const Vector<B>& Vec2)                                     //����"!="
{
    int x;
    if (Vec1.v_Weishu != Vec2.v_Weishu)
    {
        return 1;
    }
    x = Vec1.v_Weishu;
    for (int i = 0; i < x; i++)
    {
        if (Vec1.Fenliang[i] != Vec2.Fenliang[i])
        {
            return 1;
        }
    }
    return 0;
}

template<typename F>
F& Vector<F>:: operator[](int index)                                                                //����"[ ]"
{
    if (v_Weishu <= index)
    {
        int i;
        Vector<F> q(v_Weishu);
        for (i = 0; i < v_Weishu; i++)
        {
            q.Fenliang[i] = Fenliang[i];
        }
        v_Weishu = index + 1;
        delete[]Fenliang;
        Fenliang = new F[v_Weishu + 1];
        for (int j = 0; j < v_Weishu; j++)
        {
            if (j < i)
            {
                Fenliang[j] = q.Fenliang[j];
            }
            else
                Fenliang[j] = 0;
        }
        cout << "(��������ά��,�±������)";
    }
    return Fenliang[index];

}

template<typename F>
Vector<F>::Vector(int i)                                                                                //�вι�������
{
    v_Weishu = i;
    Fenliang = new F[v_Weishu + 1];
    for (int i = 0; i < v_Weishu; i++)
    {
        Fenliang[i] = 0;
    }
}
template<typename F>
Vector<F>& Vector<F>:: operator+=(const Vector<F>& Vec)throw(char, double)
{
    if (this->v_Weishu != Vec.v_Weishu)throw(char)0;
    if (this->v_Weishu == 0)throw(double)0.0;
    *this = *this + Vec;
    return *this;
}

template<class F>
Vector<F> operator+(const Vector<F>& Vec1, const Vector<F>& Vec2)throw(int, double)
{
    if (Vec1.v_Weishu != Vec2.v_Weishu) throw(int)Vec1.v_Weishu;
    if (Vec1.v_Weishu == 0 || Vec2.v_Weishu == 0)throw(double)0.0;
    Vector<F> temp(Vec1.v_Weishu);
    for (int i = 0; i < Vec2.v_Weishu; i++)
    {
        temp.Fenliang[i] = Vec1.Fenliang[i] + Vec2.Fenliang[i];
    }

    return temp;
}
/*  template<class A, class B >
  void ChangeFenliang(int i, A a, B b)const                                                       //�޸ķ���������������+�����в�ͬ�������ݵĽ��������                                                                     //�ı��������
   {
	   Fenliang[i] = a + b;
   }
*/
/*  template <class D>
	  Vector<F>& operator+ (Vector<D>& Vec)                                                            //���ء�+��
	  {
		  if (v_Weishu != Vec.GetWeishu()) throw(int)v_Weishu;
		  if (v_Weishu == 0 || Vec.GetWeishu() == 0)throw(double)0.0;
		  Vector<F> temp(v_Weishu);
		  for (int i = 0; i < v_Weishu; i++)
		  {
			  temp.ChangeFenliang(i,Fenliang[i],Vec.GetSpecificFenliang(i));
		  }
		  return temp;
	  }
*/