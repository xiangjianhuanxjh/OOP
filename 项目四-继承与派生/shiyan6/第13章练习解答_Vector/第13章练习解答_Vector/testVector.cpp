// testVector.cpp	
#include "Vector.h"
#include <fstream>
#include <cmath>
using namespace std;

int testVector()
{
	int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	double x[8];
	for(int i=0; i<8; i++)
		x[i] = sqrt(double(i));
	
	Vector<int> vi1(10, a), vi2(5, a+5);
	Vector<double> vd1(8, x), vd2(3, x);

	cout << "ԭʼ���ݣ�" << endl;
	cout << "vi1 = " << vi1 << "\nvi2 = " << vi2
		 << "\nvd1 = " << vd1 << "\nvd2 = " << vd2 << endl;

	cout << "����ά����5��" << endl;
	vi1.resize(5);
	vi2.resize(5);
	vd1.resize(5);
	vd2.resize(5);
	cout << "vi1 = " << vi1 << "\nvi2 = " << vi2
		 << "\nvd1 = " << vd1 << "\nvd2 = " << vd2 << endl;

	cout << "\n������д���ļ� vector.txt ��..." << endl;
	ofstream outfile("vector.txt");
	outfile << vi1 << '\n'
			<< vi2						
			<< vd1 << '\n' << vd2 << endl;
	outfile.close();

	cout << "\n������������(������ά����0)..." << endl;
	vi1.resize(0);
	vi2.resize(0);
	vd1.resize(0);
	vd2.resize(0);
	cout << "vi1 = " << vi1 << "\nvi2 = " << vi2
		 << "\nvd1 = " << vd1 << "\nvd2 = " << vd2 << endl;

	cout << "\n���ļ� vector.txt �ж�ȡ�����ݣ�" << endl;
	ifstream infile("vector.txt");
	infile >> vi1 >> vi2 >> vd1 >> vd2;
	infile.close();
	cout << "vi1 = " << vi1 << "\nvi2 = " << vi2
		 << "\nvd1 = " << vd1 << "\nvd2 = " << vd2 << endl;
	
	cout << "\nvi1 + vi2 = " << vi1 + vi2
		 << "\nvd1 + vd2 = " << vd1 + vd2 << endl;
	return 0;
}
