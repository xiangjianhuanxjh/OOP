#include<iostream>
#include<string>
using namespace std;
template <class F>
class Vector
{

    friend istream& operator>> (istream& cin, Vector<F>& Vec)                                       //重载>>
    {
        int n, i;
        cout << "请输入向量维数：";
        cin >> n;
        Vec.v_Weishu = n;
        F fenliang;
        Vec.ChangeWeishu(n);
        
        if (n == 0)
        {
            Vec.Fenliang[0] = 0;
            cout << "你输入了一个0向量"<<endl;
        }    
        else
        {  
            cout << "请输入向量各个分量：";
            for (i = 0; i < n; i++)
            {
                cin >> fenliang;
                Vec.Fenliang[i] = fenliang;
            }
        }
        return cin;
    }
    friend ostream& operator<<(ostream& cout, Vector<F>& Vec)                                       //重载<<
    {

       // cout << "向量维数：" << Vec.v_Weishu << endl;
        int i;
        if (Vec.v_Weishu == 0)
            cout << "0向量";
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
    void ChangeWeishu(int i);                                                                       //向量缩放函数
    F GetMaxFenliang()const;                                                                        //获取最大分量
    int GetMax() const;                                                                             //最大分量位数
    int GetWeishu()const;                                                                           //获取维数函数
    F GetSpecificFenliang(int i)const;                                                              //获取具体分量函数
    Vector();                                                                                       //默认构造函数
    Vector(int i,F *a);                                                                             //有参构造函数
    Vector(int i);
    Vector( const Vector<F>& vec);                                                                  //拷贝构造函数                       
    ~Vector();                                                                                       //析构函数
    Vector& operator= (const Vector<F>& Vec);                                                       //赋值运算符"="重载
    template<typename T, typename W>
    friend bool operator == (const Vector<T>& Vec1, const Vector<W>& Vec2);                         //重载"=="
    template<typename A, typename B>
    friend bool operator != (const Vector<A>& Vec1, const Vector<B>& Vec2);                          //重载"!="
    F& operator [](int index);                                                                       //重载"[ ]"
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
Vector<F>::Vector()                                                                                //默认构造函数
{
    v_Weishu = 0;
    Fenliang = NULL;
}
template<class F>
Vector<F>::~Vector()                                                                                //析构函数
{
    if (Fenliang != NULL)
    {
        delete[]Fenliang;
        Fenliang = NULL;
    }
}
template<class F>
F Vector<F>::GetMaxFenliang() const                                                                 //获取最大分量
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
int Vector<F>::GetMax() const                                                                       //获取最大分量位数
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
int Vector<F>:: GetWeishu()const                                                                    //获取维数
{
    return v_Weishu;
}
template<class F>
F Vector<F>::GetSpecificFenliang(int i)const                                                        //获取具体分量
{
    return Fenliang[i];
}
template<class F>
Vector<F>::Vector(int i, F* a)                                                                      //有参构造
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
Vector<F>& Vector<F>:: operator=  (const Vector<F>& Vec)                                            //重载“=”
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
Vector<F>::Vector(const Vector<F>& vec)                                                             //拷贝构造函数                                                  
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
bool operator == (const Vector<T>& Vec1, const Vector<W>& Vec2)                                     //重载“==”
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
bool operator != (const Vector<A>& Vec1, const Vector<B>& Vec2)                                     //重载"!="
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
F& Vector<F>:: operator[](int index)                                                                //重载"[ ]"
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
        cout << "(超过向量维数,下标溢出！)";
    }
    return Fenliang[index];

}

template<typename F>
Vector<F>::Vector(int i)                                                                                //有参构造重载
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
  void ChangeFenliang(int i, A a, B b)const                                                       //修改分量函数（适用于+运算中不同类型数据的解决方法）                                                                     //改变分量函数
   {
	   Fenliang[i] = a + b;
   }
*/
/*  template <class D>
	  Vector<F>& operator+ (Vector<D>& Vec)                                                            //重载“+”
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