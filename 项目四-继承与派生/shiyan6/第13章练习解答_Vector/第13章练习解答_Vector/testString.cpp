// testString.cpp	
#include "MyString.h"
#include <fstream>
using namespace std;

int testString()
{
	String str1 = "Hello", str2 = str1, str3;
	cout << "原始数据（双引号是另外添加的）：" << endl;
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	
	str3 = str2;				
	str1 = "C++ program.";
	str2 = str3 + ", world!";	
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n将数据写入文件 string.txt 中..." << endl;
	ofstream outfile("string.txt");
	outfile << str1 << '\n'
			<< str2 << '\n'
			<< str3 << endl;
	outfile.close();

	cout << "\n清除对象的数据（即调整长度到0）..." << endl;
	str1.resize(0);
	str2.resize(0);
	str3.resize(0);
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n从文件 string.txt 中读取的数据：" << endl;
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
