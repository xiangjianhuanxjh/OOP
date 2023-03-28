#include "LinkList.h"
#include "grade.h"
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
/*
int Pos(char ch, const char *str)			// ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}

int Choice(const char *prompt, const char *options = "");	// ��������
int Choice(const char *prompt, const char *options)		// �������塣�����ʾ��Ϣprompt������ѡ����ַ������ء�
{
	int key;
	cout << prompt << "{";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// ѡ��options�еĿɴ�ӡ�ַ�
			cout << options[i] << ' ';
		else														// ѡ��options�еĲ��ֿ����ַ�
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// ѡ���е�Tab�ַ�'\t'����ASCII����9��
			case '\x1b': cout << "[Esc] ";   break;					// ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
			case ' ':    cout << "[Space] "; break;					// ѡ���еĿո��ַ�' '����ASCII����32��
			}
		}
	}
	cout << "\b}: ";					// '\b'�˸�����һ��������һ�����
	do
	{
		key = getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
	cout << endl;
	return key;
}

int main()
{
	int Pos(char ch, const char *str);						// ��������
	int Choice(const char *prompt, const char *options = "");	// ��������
	LinkList<Student> uLink;
	//Student xStudent;
	//Node<Student> *pS;
	//Grade xgrade;
	int key, k, n,yn;
	while (true)
	{
		cout << "\n\n========= �ɼ�����ϵͳ =========" << endl;
		cout << "  1 ---- ���ѧ����Ϣ (P)" << endl;
		cout << "  2 ---- ¼��ѧ����Ϣ (I)" << endl;
		cout << "  3 ---- ��        ѯ (S)" << endl;
		cout << "  4 ---- ��        �� (O)" << endl;
		cout << "  5 ---- ͳ        �� (T)" << endl;
		cout << "  6 ---- ɾ��ѧ������ (D)" << endl;
		cout << "  7 ---- ����������� (Q)" << endl;
		cout << "  0 ---- ��      �� (ESC)" << endl;
		cout << "==========================" << endl;
		key = Choice("��ѡ��", "0123456789\x1bpPiIaAsSvVoOwWrRfF");
		cout << "\n\n";
		if (key == 27 || key == '0')		// '\x1b'����27��ָESC��
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
		case '4':	cout << "������� 1��ѧ�ţ�2����������ѡ��: ";
			k = getche();
			switch (k)
			{
			case '1':   uLink.Sort(string(""));
				cout << "\n��ѧ�ţ�����������\n" << uLink << endl;
				uLink.Sort(string(""), false);
				cout << "��ѧ�ţ�����������\n" << uLink << endl;	break;
			case '2':	uLink.Sort(string(""));
				cout << "\n������������������\n" << uLink << endl;
				uLink.Sort(string(""), false);
				cout << "������������������\n" << uLink << endl;	break;
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
		case 'Q':	cout << "ɾ������ѧ�����ݡ��Ƿ����(y/[N])? ";
			yn = getche();
			if (yn == 'y' || yn == 'Y')				// Ĭ�� No
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
	cout << "�˳���";
	cin >> choose;
	if (choose != 'y')
		return main;
	else
		return 0;

}