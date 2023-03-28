#ifndef GRADE_H
#define GRADE_H
#include "LinkList.h"
#include <iomanip>
#include <string>

class Student;

class Grade
{
public:
	Grade(const char  *Kemu = "math", double Jidian = 0);
	void Set(const char *Kemu, double Jidian);
	//void Search(LinkList<Grade> &link);
	friend class Student;
	friend ostream & operator<<(ostream &out, const Grade &g);
private:
	string kemu;            //科目
	double jidian;           //该科目的绩点,总均绩

};

class Student
{
public:
	Student(const char *Xuehao = "00003721", const char *Name = "NoName");
	void Set(const char *Xuehao, const char *Name);
	operator string() const;
	void AppendGrade(const Grade &g);
	void Show(ostream &out) const;
	friend ostream & operator<<(ostream &out, const Student &s);
	double junji;
private:
	string xuehao, name;		// 学号、名字
	LinkList<Grade> link;		// 链表(该学生的成绩)
};

////////////////////////////////////////
void SetStudent(LinkList<Student> & uLink);
void DeleteStudent(LinkList<Student> & uLink);
////////////////////////////////////////
void TongJi(LinkList<Student> & uLink);
void search(LinkList<Student> & uLink);
#endif