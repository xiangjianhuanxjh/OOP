#include "test.h"
#include "Vector.hpp"

void test01()                                                //向量维度缩放功能测试
{
    cout << "--------------------------------------向量维度缩放功能测试-----------------------------------------" << endl;
    int a[3] = {
        1,2,3
    };
    double b[3] = {
        1.01,2.01,3.01
    };
    float c[3] = {
        1.1,2.1,3.1
    };
    Vector<int> p1(3, a);
    Vector<double> p2(3, b);
    Vector<float> p3(3, c);
    cout << "int型向量p1" << p1 << "维度缩放测试" << endl;
    p1.ChangeWeishu(2);
    cout << "维度收缩结果：p1" << p1 << endl;
    p1.ChangeWeishu(4);
    cout << "维度放大结果：p1" << p1 << endl;
    cout << "double型向量p2" << p2 << "维度缩放测试" << endl;
    p2.ChangeWeishu(2);
    cout << "维度收缩结果：p2" << p2 << endl;
    p2.ChangeWeishu(4);
    cout << "维度放大结果：p2" << p2 << endl;
    cout << "float型向量p3" << p3 << "维度缩放测试" << endl;
    p3.ChangeWeishu(2);
    cout << "维度收缩结果：p3" << p3 << endl;
    p3.ChangeWeishu(4);
    cout << "维度放大结果：p3" << p3 << endl;

}
void test02()                                                                //构造函数、赋值功能功能测试
{
    cout << "--------------------------------------构造函数与赋值运算符功能测试-----------------------------------------" << endl;
    int a[3] = {
        1,2,3
    };
    int b[3] = {
        2,4,6
    };
    Vector<int> p1;
    Vector<int> p2(3, a);
    Vector<int> p3(p2);
    Vector<int> p4(3, b);
    //默认构造
    cout << "通过默认构造创建p1向量：p1" << p1 << endl;
    //有参构造
    cout << "通过有参构造创建p2向量：p2" << p2 << endl;
    //拷贝构造
    cout << "通过拷贝构造创建p3向量(拷贝内容来自p2)：p3" << p3 << endl;
    //赋值运算
    cout << "将p1维数放大后进行赋值操作p1=p2" << endl;
    p1.ChangeWeishu(3);
    p1 = p2;
    cout << "赋值结果：p1" << p1 << endl;
    p1 = p2 = p3 = p4;
    cout << "赋值操作p1=p2=p3=p4" << endl;
    cout << "赋值结果：" << endl
        << "    p1" << p1 << endl
        << "    p2" << p2 << endl
        << "    p3" << p3 << endl
        << "    p4" << p4 << endl;

}
void test03()                                                       //其他成员函数功能测试

{
    cout << "--------------------------------------其他成员函数功能测试-----------------------------------------" << endl;
    cout << "--------包括： 获取最大分量函数、获取最大分量所在维数函数、获取维数函数、获取具体分量函数----------" << endl;
    int a[6] = {
       1,2,3,6,5,4
    };
    Vector<int> p(6, a);
    cout << "对于向量p" << p << endl;
    //获取最大分量
    cout << "向量p最大分量为：" << p.GetMaxFenliang() << endl;
    //获取最大分类所在维数
    cout << "向量p最大分量所在维数为：" << p.GetMax() << endl;
    //获取维数
    cout << "向量p维数为：" << p.GetWeishu() << endl;
    //获取具体分量
    int i;
    cout << "向量p各个维度上分量分别为：" << endl;
    for (i = 0; i < p.GetWeishu(); i++)
    {
        cout << "   第" << i + 1 << "个分量为：" << p.GetSpecificFenliang(i) << endl;
    }
}
void test04()               //运算符功能测试   >> == !=
{
    cout << "--------------------------------------运算符 >>、 ==、 != 功能测试--------------------------------------" << endl;
    int a[3] = {
        1,2,3
    };
    int b[3] = {
        2,4,6
    };
    double c[3] = {
        1,2,3
    };
    float d[3] = {
        1,2,3
    };
    float e[3] = {
        2,4,6
    };
    Vector<int> p1(3, a);
    Vector<int> p2(3, b);
    Vector<int> p3(p1);
    Vector<double> p4(3, c);
    Vector<float> p5(3, d);
    Vector<float> p6(3, e);
    Vector<int> p;
    cout << "int型     p1" << p1 << endl
        << "int型     p2" << p2 << endl
        << "int型     p3" << p3 << endl
        << "double型  p4" << p4 << endl
        << "float型   p5" << p5 << endl
        << "float型   p6" << p6 << endl;
    cout << "运算符>>功能测试" << endl;
    cin >> p;
    cout << "输入的向量为：" << p << endl;
    cin >> p;
    cout << "输入的向量为：" << p << endl;
    cout << "运算符==功能测试" << endl;
    cout << "   int-int 型测试：    ";
    if (p1 == p3) cout << "p1==p3" << endl;
    cout << "   int-double 型测试： ";
    if (p1 == p4) cout << "p1==p4" << endl;
    cout << "   int-float 型测试：  ";
    if (p1 == p5) cout << "p1==p5" << endl;
    cout << "   double-float 型测试 ";
    if (p4 == p5) cout << "p4==p5" << endl;
    cout << "运算符!=功能测试" << endl;
    cout << "   int-int 型测试：    ";
    if (p1 != p2) cout << "p1!=p2" << endl;
    cout << "   int-double 型测试： ";
    if (p2 != p4) cout << "p2!=p4" << endl;
    cout << "   int-float 型测试：  ";
    if (p2 != p5) cout << "p2!=p5" << endl;
    cout << "   double-float 型测试 ";
    if (p4 != p6) cout << "p4!=p6" << endl;
}
void test05()
{
    cout << "--------------------------------------运算符[]功能测试--------------------------------------" << endl;
    int a[3] = {
        1,2,3
    };
    Vector<int> p(3, a);
    cout << "先构造一个向量p(1,2,3)" << endl;
    cout << "用[]输出向量p的每个分量:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "p["<<i<<"]=" << p[i] <<endl;
    }
    cout << endl << "测试运算下标越界的异常情况p[3](当下标越界时,提醒出错,并返还0):" << endl;
    cout <<"p[3]=" << p[p.GetWeishu()] << endl;
}
void test06()//+ += 运算符功能测试
{
    cout << "-----------------------------------+ +=运算符功能测试---------------" << endl;
    Vector<int> p;
    Vector<int> y;
    Vector<int> m;
    //Vector<int> x;
    cin >> p;
    cin >> y;
    cin >> m;
    Vector<int> x(m);
    
    Vector<int> q(p.GetWeishu());
    try
    {
        q = p + y;
        m += y;
    }
    catch (int)
    {
        cout << "执行+运算时需要向量维数一致，无法运算并返回0向量：";
    }
    catch (char)
    {
        cout << "执行+=运算时需要向量维数一致" << endl;
    }
    catch (double)
    {
        cout << "不支持0向量运算" << endl;
    }
    cout << q<<endl;
    if (x == m) cout << "执行+=运算需要向量维数一致，无法运算并返回原向量：";
        cout << m;
}
