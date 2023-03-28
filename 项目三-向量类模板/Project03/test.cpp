#include "test.h"
#include "Vector.hpp"

void test01()                                                //����ά�����Ź��ܲ���
{
    cout << "--------------------------------------����ά�����Ź��ܲ���-----------------------------------------" << endl;
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
    cout << "int������p1" << p1 << "ά�����Ų���" << endl;
    p1.ChangeWeishu(2);
    cout << "ά�����������p1" << p1 << endl;
    p1.ChangeWeishu(4);
    cout << "ά�ȷŴ�����p1" << p1 << endl;
    cout << "double������p2" << p2 << "ά�����Ų���" << endl;
    p2.ChangeWeishu(2);
    cout << "ά�����������p2" << p2 << endl;
    p2.ChangeWeishu(4);
    cout << "ά�ȷŴ�����p2" << p2 << endl;
    cout << "float������p3" << p3 << "ά�����Ų���" << endl;
    p3.ChangeWeishu(2);
    cout << "ά�����������p3" << p3 << endl;
    p3.ChangeWeishu(4);
    cout << "ά�ȷŴ�����p3" << p3 << endl;

}
void test02()                                                                //���캯������ֵ���ܹ��ܲ���
{
    cout << "--------------------------------------���캯���븳ֵ��������ܲ���-----------------------------------------" << endl;
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
    //Ĭ�Ϲ���
    cout << "ͨ��Ĭ�Ϲ��촴��p1������p1" << p1 << endl;
    //�вι���
    cout << "ͨ���вι��촴��p2������p2" << p2 << endl;
    //��������
    cout << "ͨ���������촴��p3����(������������p2)��p3" << p3 << endl;
    //��ֵ����
    cout << "��p1ά���Ŵ����и�ֵ����p1=p2" << endl;
    p1.ChangeWeishu(3);
    p1 = p2;
    cout << "��ֵ�����p1" << p1 << endl;
    p1 = p2 = p3 = p4;
    cout << "��ֵ����p1=p2=p3=p4" << endl;
    cout << "��ֵ�����" << endl
        << "    p1" << p1 << endl
        << "    p2" << p2 << endl
        << "    p3" << p3 << endl
        << "    p4" << p4 << endl;

}
void test03()                                                       //������Ա�������ܲ���

{
    cout << "--------------------------------------������Ա�������ܲ���-----------------------------------------" << endl;
    cout << "--------������ ��ȡ��������������ȡ����������ά����������ȡά����������ȡ�����������----------" << endl;
    int a[6] = {
       1,2,3,6,5,4
    };
    Vector<int> p(6, a);
    cout << "��������p" << p << endl;
    //��ȡ������
    cout << "����p������Ϊ��" << p.GetMaxFenliang() << endl;
    //��ȡ����������ά��
    cout << "����p����������ά��Ϊ��" << p.GetMax() << endl;
    //��ȡά��
    cout << "����pά��Ϊ��" << p.GetWeishu() << endl;
    //��ȡ�������
    int i;
    cout << "����p����ά���Ϸ����ֱ�Ϊ��" << endl;
    for (i = 0; i < p.GetWeishu(); i++)
    {
        cout << "   ��" << i + 1 << "������Ϊ��" << p.GetSpecificFenliang(i) << endl;
    }
}
void test04()               //��������ܲ���   >> == !=
{
    cout << "--------------------------------------����� >>�� ==�� != ���ܲ���--------------------------------------" << endl;
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
    cout << "int��     p1" << p1 << endl
        << "int��     p2" << p2 << endl
        << "int��     p3" << p3 << endl
        << "double��  p4" << p4 << endl
        << "float��   p5" << p5 << endl
        << "float��   p6" << p6 << endl;
    cout << "�����>>���ܲ���" << endl;
    cin >> p;
    cout << "���������Ϊ��" << p << endl;
    cin >> p;
    cout << "���������Ϊ��" << p << endl;
    cout << "�����==���ܲ���" << endl;
    cout << "   int-int �Ͳ��ԣ�    ";
    if (p1 == p3) cout << "p1==p3" << endl;
    cout << "   int-double �Ͳ��ԣ� ";
    if (p1 == p4) cout << "p1==p4" << endl;
    cout << "   int-float �Ͳ��ԣ�  ";
    if (p1 == p5) cout << "p1==p5" << endl;
    cout << "   double-float �Ͳ��� ";
    if (p4 == p5) cout << "p4==p5" << endl;
    cout << "�����!=���ܲ���" << endl;
    cout << "   int-int �Ͳ��ԣ�    ";
    if (p1 != p2) cout << "p1!=p2" << endl;
    cout << "   int-double �Ͳ��ԣ� ";
    if (p2 != p4) cout << "p2!=p4" << endl;
    cout << "   int-float �Ͳ��ԣ�  ";
    if (p2 != p5) cout << "p2!=p5" << endl;
    cout << "   double-float �Ͳ��� ";
    if (p4 != p6) cout << "p4!=p6" << endl;
}
void test05()
{
    cout << "--------------------------------------�����[]���ܲ���--------------------------------------" << endl;
    int a[3] = {
        1,2,3
    };
    Vector<int> p(3, a);
    cout << "�ȹ���һ������p(1,2,3)" << endl;
    cout << "��[]�������p��ÿ������:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "p["<<i<<"]=" << p[i] <<endl;
    }
    cout << endl << "���������±�Խ����쳣���p[3](���±�Խ��ʱ,���ѳ���,������0):" << endl;
    cout <<"p[3]=" << p[p.GetWeishu()] << endl;
}
void test06()//+ += ��������ܲ���
{
    cout << "-----------------------------------+ +=��������ܲ���---------------" << endl;
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
        cout << "ִ��+����ʱ��Ҫ����ά��һ�£��޷����㲢����0������";
    }
    catch (char)
    {
        cout << "ִ��+=����ʱ��Ҫ����ά��һ��" << endl;
    }
    catch (double)
    {
        cout << "��֧��0��������" << endl;
    }
    cout << q<<endl;
    if (x == m) cout << "ִ��+=������Ҫ����ά��һ�£��޷����㲢����ԭ������";
        cout << m;
}
