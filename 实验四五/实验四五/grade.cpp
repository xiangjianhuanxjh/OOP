#include "LinkList.h"
#include "grade.h"
#include <iomanip>
#include <string>
#include <conio.h>

Grade::Grade(const char  *Kemu, double Jidian) : kemu(Kemu),jidian(Jidian)
{
}

void Grade::Set(const char  *Kemu, double Jidian)
{
	kemu = Kemu;
	jidian = Jidian;
}


ostream & operator<<(ostream &out, const Grade &g)
{
	out << setfill('0');
	out << g.kemu << '\t' << g.jidian;
	//out << '\t' << g.junji << setfill(' ');
	return out;
}

//////////////////////////////////////////////////////////

Student::Student(const char *Xuehao, const char *Name) : xuehao(Xuehao), name(Name)
{
}

void Student::Set(const char *Xuehao, const char *Name)
{
	xuehao = Xuehao;
	name = Name;
}

void Student::AppendGrade(const Grade &g)
{

	double x;
	Grade y(g);
	if (link.NumNodes() == 0)
		x = 0;
	else
	{
		link.GoBottom();
		x = link.CurData().jidian;
	}

	link.Append(y);				// ���һ�ųɼ�
}

void Student::Show(ostream &out) const
{
	out << "ѧ�ţ�" << xuehao << "\t������" << name <<"\t����" << junji << endl;
}

ostream & operator<<(ostream &out, const Student &s)
{
	s.Show(out);
	out << "��Ŀ\t����" << endl;
	s.link.PutList(out);
	return out;
}

Student::operator string() const
{
	return xuehao;
}
////////////////////////////////////////////////////////
void SetStudent(LinkList<Student> & uLink)
{
	Student xStudent;
	Grade xGrade;
	char name[80], xuehao[80], kecheng[80], str[80];
	//const char *xueke[] = { "����","��ѧ","Ӣ��","����","��ѧ","����" };
	cout << "������ѧ��ѧ��: ";
	cin.getline(xuehao, 80);
	cout << "������ѧ������: ";
	cin.getline(name, 80);
	xStudent.Set(xuehao, name);

	int i, n;
	double sum = 0, score, junji;
	cout << "������¼��γ̵�������";
	cin >> n;
	cin.getline(str, 80);
	i = n;
	while (n--)
	{
		/*cout<<"������ѧ�ƣ�";
		char XK[80];
		cin.getline(XK,80);
		cout<<"�����뼨�㣺";
		cin>>score;
		xGrade.Set(XK,score);
		xStudent.AppendGrade(xGrade);
		cin.getline(str, 80);
			*/
		cout << "������γ����ƣ�";
		cin.getline(kecheng, 80);
		cout << "������ÿγ̵õ��ļ��㣺";
		cin >> score;
		cin.getline(str, 80);
		xGrade.Set(kecheng, score);
		xStudent.AppendGrade(xGrade);
		sum = score + sum;
		junji = sum / i;
	}
	xStudent.junji = junji;
	uLink.Append(xStudent);
}

void DeleteStudent(LinkList<Student> & uLink)
{
	Student xUser;
	Node<Student> *pS;
	Grade xgrade;
	char name[80], id[80], str[80];
	cout << "������ѧ��ѧ��: ";

	cin.getline(id, 80);
	xUser.Set(id, "");
	pS = uLink.Locate(string(xUser), true);
	if (pS == NULL)
	{
		cout << "�޴�ѧ����" << endl;
	}
	else {
		uLink.DeleteCurNode();
		cout << "ɾ���ɹ���" << endl;
	}
}
///////////////////////////////////////////////////////
void TongJi(LinkList<Student> & uLink)
{
	Student xStudent;
	Node<Student> *pS;
	Grade xgrade;
	char kemu[80],str[80];
	double junji, min, max;
	int n=0;
	pS = uLink.GoTop();
	if (pS == NULL)
	{
		cout << "û��ѧ����Ϣ���޷�ͳ�ƣ�" << endl;
	}
	else
	{
		cout << "������ͳ�Ƶľ�����Χ��" << endl;
		cout << "min��";
		cin >> min;
		cin.getline(str, 80);
		cout << "max��";
		cin >> max;
		cin.getline(str, 80);
		for (; pS != NULL; pS = uLink.Skip(1))
		{
			if (uLink.CurData().junji >= min && uLink.CurData().junji <= max)
			{
				n++;
				cout << "����Ϊ����Ҫ���ѧ��";
				cout << uLink.CurData();
			}
		}
		cout << "����" << n << "��ѧ���ڷ�Χ��";
	}
}

/////////////////////////////////////////////////////
void search(LinkList<Student> & uLink)
{
	char x[80];

	cout << "������Ҫ��ѯ��ѧ��: ";
	cin.getline(x, 80);
	Node<Student> *p;
	p = uLink.Locate(string(x), true);
	int n = 0;
	while (p != NULL)
	{
		cout << "�ҵ��� " << uLink.CurPos() << " ���(��Ŵ�0��ʼ)��\n" << uLink.CurData() << endl;
		n++;
		p = uLink.Locate(string(x));
	}
	cout << "\t���ҵ� " << n << " �������������" << endl;
	uLink.GoTop();

}
