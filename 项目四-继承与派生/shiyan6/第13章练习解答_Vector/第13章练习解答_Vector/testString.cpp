// testString.cpp	
#include "MyString.h"
#include <fstream>
using namespace std;

int testString()
{
	String str1 = "Hello", str2 = str1, str3;
	cout << "ԭʼ���ݣ�˫������������ӵģ���" << endl;
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	
	str3 = str2;				
	str1 = "C++ program.";
	str2 = str3 + ", world!";	
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n������д���ļ� string.txt ��..." << endl;
	ofstream outfile("string.txt");
	outfile << str1 << '\n'
			<< str2 << '\n'
			<< str3 << endl;
	outfile.close();

	cout << "\n�����������ݣ����������ȵ�0��..." << endl;
	str1.resize(0);
	str2.resize(0);
	str3.resize(0);
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n���ļ� string.txt �ж�ȡ�����ݣ�" << endl;
	ifstream infile("string.txt");
	infile >> str1 >> str2 >> str3;		
	getline(infile, str1, 100);			
	getline(infile, str2, 100);
	getline(infile, str3, 100);
	infile.close();
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	return 0;
}
