// test.cpp		
#include "Vector.h"
#include "MyString.h"
#include <fstream>
#include <conio.h>
using namespace std;

int testVector(), testString(), test();

int testStrCmp()
{
	char array[][20] = {"abc", "abcd", "ab", "ae", "aa", "ABC", "xyz", "汉字串"};
	int n = sizeof(array)/sizeof(*array);
	String str0="abc", str1;

	cout << boolalpha;
	for(int i=0; i<n; i++)
	{
		str1 = array[i];
		cout << "\"" << str0 << "\" > \"" << str1 << "\"\t: " << (str0 > str1) << endl;
	}
	cout << noboolalpha;
	return 0;
}

int main()
{
	int choice=1;
	while(choice)
	{
		cout << "\n1 --- testing Vector          [v]"
			 << "\n2 --- testing String          [s]"
			 << "\n3 --- testing Vector & String [m]"
			 << "\n0 --- exit                    [q]"
			 << endl;
		choice = getch();
		switch(choice)
		{
		case '1':
		case 'v':
		case 'V':	testVector();	break;
		case '2':
		case 's':
		case 'S':	testString();	break;
		case '3':
		case 'm':
		case 'M':	test();			break;
		case '0':
		case 'q':
		case 'Q':
		case 27:	choice = 0;		break;
		}
	}
	return 0;
}

int test()
{
	testStrCmp();

	Vector<int> v;
	String str;

	cout << "请输入一个整数向量。如 (1, 3, 5, 7)" << endl;
	cin >> v;
	cout << v << endl;
	getchar();		
	cout << "请输入一个字符串。如 abc 12345   xyz" << endl;

					
	cin >> str;	
	cout << str << endl;

	cout << "\n将数据写入文件 output.txt 中..." << endl;
	ofstream outfile("output.txt");
	outfile << v << endl
			<< str << endl;
	outfile.close();

	cout << "\n清除对象的数据..." << endl;
	v.resize(0);
	str.resize(0);
	cout << "向量：" << v << endl
		 << "字符串：\"" << str << "\"" << endl;

	cout << "\n从文件 output.txt 中读取的数据：" << endl;
	ifstream infile("output.txt");
	infile >> v;
//	infile >> str;				
	getline(infile, str, 100);	
	getline(infile, str, 100);	
	infile.close();
	cout << "向量：" << v << endl
		 << "字符串：\"" << str << "\"" << endl;
	return 0;
}
