#include "LinkList.h"
#include "grade.h"
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
/*
int Pos(char ch, const char *str)			// 返回指定字符ch在字符串str中的下标。不存在时返回-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}

int Choice(const char *prompt, const char *options = "");	// 函数声明
int Choice(const char *prompt, const char *options)		// 函数定义。输出提示信息prompt，输入选择的字符并返回。
{
	int key;
	cout << prompt << "{";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// 选项options中的可打印字符
			cout << options[i] << ' ';
		else														// 选项options中的部分控制字符
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// 选项中的Tab字符'\t'（即ASCII编码9）
			case '\x1b': cout << "[Esc] ";   break;					// 选项中的Esc字符'\x1b'（即ASCII编码27）
			case ' ':    cout << "[Space] "; break;					// 选项中的空格字符' '（即ASCII编码32）
			}
		}
	}
	cout << "\b}: ";					// '\b'退格。先退一格，在输出右花括号
	do
	{
		key = getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // 若options为空长度为0的字符串，则输入无限制；否则输入项应该在optins中。
	cout << endl;
	return key;
}

int main()
{
	int Pos(char ch, const char *str);						// 函数声明
	int Choice(const char *prompt, const char *options = "");	// 函数声明
	LinkList<Student> uLink;
	//Student xStudent;
	//Node<Student> *pS;
	//Grade xgrade;
	int key, k, n,yn;
	while (true)
	{
		cout << "\n\n========= 成绩管理系统 =========" << endl;
		cout << "  1 ---- 输出学生信息 (P)" << endl;
		cout << "  2 ---- 录入学生信息 (I)" << endl;
		cout << "  3 ---- 查        询 (S)" << endl;
		cout << "  4 ---- 排        序 (O)" << endl;
		cout << "  5 ---- 统        计 (T)" << endl;
		cout << "  6 ---- 删除学生数据 (D)" << endl;
		cout << "  7 ---- 清除所有数据 (Q)" << endl;
		cout << "  0 ---- 退      出 (ESC)" << endl;
		cout << "==========================" << endl;
		key = Choice("请选择", "0123456789\x1bpPiIaAsSvVoOwWrRfF");
		cout << "\n\n";
		if (key == 27 || key == '0')		// '\x1b'等于27，指ESC键
			break;
		switch (key)
		{
		case '1':	cout << uLink << endl;
			break;
		case 'p':
		case 'P':
		case '2':	SetStudent(uLink);
			break;
		case 'i':
		case 'I':
		case '3':	search(uLink);
			break;
		case 's':
		case 'S':
		case '4':	cout << "排序根据 1按学号，2按姓名。请选择: ";
			k = getche();
			switch (k)
			{
			case '1':   uLink.Sort(string(""));
				cout << "\n按学号（升序）排序结果\n" << uLink << endl;
				uLink.Sort(string(""), false);
				cout << "按学号（降序）排序结果\n" << uLink << endl;	break;
			case '2':	uLink.Sort(string(""));
				cout << "\n按姓名（升序）排序结果\n" << uLink << endl;
				uLink.Sort(string(""), false);
				cout << "按姓名（降序）排序结果\n" << uLink << endl;	break;
			}
			break;
		case 'o':
		case 'O':
		case '5':	TongJi(uLink);
			break;
		case 'r':
		case 'R':
		case '6':	DeleteStudent(uLink);
			break;
		case 'd':
		case 'D':
		case '7':
		case 'q':
		case 'Q':	cout << "删除所有学生数据。是否继续(y/[N])? ";
			yn = getche();
			if (yn == 'y' || yn == 'Y')				// 默认 No
				uLink.FreeList();							break;
		}
	}
}
*/
void avg(int a,int b,int c)
{
	cout << "pinjun" << (a+b+c)/3;

}
int main()
{
	int a, b, c;
	char choose;
	cin >> a >> b >> c;
	avg(a, b, c);
	cout << "退出否";
	cin >> choose;
	if (choose != 'y')
		return main;
	else
		return 0;

}