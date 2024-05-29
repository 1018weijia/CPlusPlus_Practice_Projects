#pragma once
#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	string name = "";
	int student_num = 0;
public:
	student(string name_, int stud_num);//构造函数
	void setname(string name_);
	void setnum(int stud_num);
	//重载小于号,在map中需要使用
	bool operator<(const student& s)const;
};

//构造函数
student::student(string name_, int stud_num)
{
	this->setname(name_);
	this->setnum(stud_num);

}

//设置姓名
void student::setname(string name_)
{
	this->name = name_;
}

//设置学号
void student::setnum(int stud_num)
{
	this->student_num = stud_num;
}

//重载运算符,因为要使用map容器
bool student::operator <(const student& s) const
{
	if (this->student_num < s.student_num)
		return true;
	else
		return false;
}