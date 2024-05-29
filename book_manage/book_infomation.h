#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"student.h"
using namespace std;
//设计图书类，包含图书的信息
class book
{
//数据部分
public:
	string book_name = "";//图书的名字
	int book_identifier = 0;//图书的编号
	string author_name = "";//作者的名字
	int book_case = 0;//设置图书状态,1是在架,0是已经全部借出
	int book_num = 0;//设置该图书的库存数量,当该库存数为0时,book_case的数值变更为0
	map<student,int> borrowers;//存储该图书借出者的名字
//函数部分
public:
	book(string book_name,string book_author,int book_identifier);//构造函数
	void set_name(string book_name_);//设置图书名称,图书管理员系统使用
	void set_identifier(int identifier);//设置图书编号,图书管理员系统使用
	void set_author(string name);//设置图书的作者名称,图书管理员系统使用
	void set_case(int bor_num);//设置图书的状态,bor_num为借出/还回的数量,用于改变book_num和book_case
	void set_borrow(student stud,int time);//设置该图书借出者的名单,名字和借出时间,使用map类型容器
	void print();//打印该图书的信息
	bool operator < (const book& b) const;//重载小于号运算符
};

//函数实现

//构造函数
book::book(string book_name_, string book_author, int book_identifier_)
{
	this->book_name = book_name_;
	this->book_identifier = book_identifier_;
	this->author_name = book_author;

}


//设置图书名称,图书管理员使用
void book::set_name(string book_name_)
{
	this->book_name = book_name_;
}

//设置图书编号,图书管理员使用
void book::set_identifier(int identifier)
{
	this->book_identifier = identifier;
}

//设置图书的作者名称,图书管理员使用
void book::set_author(string name)
{
	this->author_name = name;
}

//设置图书的状态,bor_num为借出/还回的数量,图书管理员使用
void book::set_case(int bor_num)
{
	if (bor_num < 0)//如果要借出的数量大于库存数量,需要说明并报错
	{
		if (-(bor_num) > this->book_num)
			cout << "			书籍库存不足" << endl;
		else
		{
			cout << "			借出成功" << endl;
			this->book_num = this->book_num + bor_num;//否则直接加上数字就行,数字可正可负
		}
			
	}
	else
	{

		cout << "			增加该图书" << bor_num <<"本" << endl;
		this->book_num = this->book_num + bor_num;
	}
}

//设置该图书借出者的名单,名字和借出时间,使用map类型容器
void book::set_borrow(student stud, int time)
{
	this->borrowers[stud] = time;
}

//打印图书信息
void book::print()
{
	cout << "			书名:" << this->book_name << endl;
	cout << "			作者名:" << this->author_name << endl;
	cout << "			图书编号:" << this->book_identifier << endl;
	cout << "			图书存量:" << this->book_num << endl;
}

//重载小于号运算符
bool book::operator <(const book& b) const
{
	if (this->book_identifier < b.book_identifier)
		return true;
	else
		return false;
}
