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
	student(string name_, int stud_num);//���캯��
	void setname(string name_);
	void setnum(int stud_num);
	//����С�ں�,��map����Ҫʹ��
	bool operator<(const student& s)const;
};

//���캯��
student::student(string name_, int stud_num)
{
	this->setname(name_);
	this->setnum(stud_num);

}

//��������
void student::setname(string name_)
{
	this->name = name_;
}

//����ѧ��
void student::setnum(int stud_num)
{
	this->student_num = stud_num;
}

//���������,��ΪҪʹ��map����
bool student::operator <(const student& s) const
{
	if (this->student_num < s.student_num)
		return true;
	else
		return false;
}