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

	link.Append(y);				// 添加一门成绩
}

void Student::Show(ostream &out) const
{
	out << "学号：" << xuehao << "\t姓名：" << name <<"\t均绩" << junji << endl;
}

ostream & operator<<(ostream &out, const Student &s)
{
	s.Show(out);
	out << "科目\t绩点" << endl;
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
	//const char *xueke[] = { "语文","数学","英语","物理","化学","生物" };
	cout << "请输入学生学号: ";
	cin.getline(xuehao, 80);
	cout << "请输入学生姓名: ";
	cin.getline(name, 80);
	xStudent.Set(xuehao, name);

	int i, n;
	double sum = 0, score, junji;
	cout << "请输入录入课程的门数：";
	cin >> n;
	cin.getline(str, 80);
	i = n;
	while (n--)
	{
		/*cout<<"请输入学科：";
		char XK[80];
		cin.getline(XK,80);
		cout<<"请输入绩点：";
		cin>>score;
		xGrade.Set(XK,score);
		xStudent.AppendGrade(xGrade);
		cin.getline(str, 80);
			*/
		cout << "请输入课程名称：";
		cin.getline(kecheng, 80);
		cout << "请输入该课程得到的绩点：";
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
	cout << "请输入学生学号: ";

	cin.getline(id, 80);
	xUser.Set(id, "");
	pS = uLink.Locate(string(xUser), true);
	if (pS == NULL)
	{
		cout << "无此学生！" << endl;
	}
	else {
		uLink.DeleteCurNode();
		cout << "删除成功！" << endl;
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
		cout << "没有学生信息，无法统计！" << endl;
	}
	else
	{
		cout << "请输入统计的均绩范围：" << endl;
		cout << "min：";
		cin >> min;
		cin.getline(str, 80);
		cout << "max：";
		cin >> max;
		cin.getline(str, 80);
		for (; pS != NULL; pS = uLink.Skip(1))
		{
			if (uLink.CurData().junji >= min && uLink.CurData().junji <= max)
			{
				n++;
				cout << "下列为符合要求的学生";
				cout << uLink.CurData();
			}
		}
		cout << "共有" << n << "个学生在范围中";
	}
}

/////////////////////////////////////////////////////
void search(LinkList<Student> & uLink)
{
	char x[80];

	cout << "请输入要查询的学号: ";
	cin.getline(x, 80);
	Node<Student> *p;
	p = uLink.Locate(string(x), true);
	int n = 0;
	while (p != NULL)
	{
		cout << "找到第 " << uLink.CurPos() << " 结点(编号从0开始)：\n" << uLink.CurData() << endl;
		n++;
		p = uLink.Locate(string(x));
	}
	cout << "\t共找到 " << n << " 个结点满足条件" << endl;
	uLink.GoTop();

}
