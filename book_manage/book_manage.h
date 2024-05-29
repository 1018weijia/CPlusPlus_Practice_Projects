#pragma once
#include"book_infomation.h"
using namespace std;
//图书管理系统,用于图书信息的增删修改,供图书管理员使用
class manage
{
public:
	vector<book> library;//定义图书馆vector,存放书籍类
public:
	void add_book();//增加图书功能,需要调用书籍类的函数
	void delete_book(string book_name);//删除书籍功能
	void set_book();//修改书籍功能
	void print_all_book();//显示全部图书功能
	bool find_book(string book_name);//按书名查找某本书是否存在,存在则打印其信息,否则显示查无此书
	void find_author(string author);//按作家来查找其作品
	void find_identifier(int identifier);//按编号来查找书籍
	void borrow_book(string book, int time);//借阅图书，以及时间
	void return_book(string book);//归还图书

};

//增加书籍,创建书类
void manage::add_book()
{
	string b_name, b_author;
	int b_identifier;
	cout << "			请输入书籍名称:			" << endl;
	cin >> b_name;
	cout << "			请输入书籍作者名:		" << endl;
	cin >> b_author;
	cout << "			请输入书籍编号:			" << endl;
	cin >> b_identifier;
	book temp(b_name,b_author,b_identifier);
	int add_num;
	cout << "			请输入增加的书籍数量:		" << endl;
	cin >> add_num;
	temp.book_num = temp.book_num + add_num;
	library.push_back(temp);
}

//删除书籍
void manage::delete_book(string book_name_)
{
	//遍历vector容器,查找同名书籍
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_name == book_name_)
		{
			i = library.erase(i);
			mark = 1;
			break;
		}
		else
		{
			i++;
		}
	}
	if (mark == 0)
	{
		cout << "			查无此书" << endl;
	}
}

//修改书籍功能
void manage::set_book()
{
	cout << "			请输入需要更改的书籍的名字:" << endl;
	string b_name;
	cin >> b_name;
	//设置要修改的内容的项数func_num,exit_mark为标识符,判断是否要退出修改内容
	int func_num,exit_mark=0;
	cout << "			请输入要修改的内容的项数(1~3):" << endl;
	cin >> func_num;
	for (int time = 0; time < func_num; time++)
	{
		cout << "			请选择要修改的内容" << endl;
		cout << "			输入1:修改书籍名字" << endl;
		cout << "			输入2:修改书籍作者名" << endl;
		cout << "			输入3:修改书籍编号" << endl;
		cout << "			输入4:退出修改" << endl;
		int choose_function;
		cin >> choose_function;
		int false_times = 0;//设置允许错误的次数
		while (choose_function != 1 && choose_function != 2 && choose_function != 3 && choose_function != 4)
		{
			cout << "			输入错误,请重新输入" << endl;
			false_times++;
			if (false_times == 3)
			{
				break;//如果错误次数达到3次,则退出输入
			}
			cin >> choose_function;
		}
		switch (choose_function)
		{
		case 1:
		{
			cout << "			请输入要修改成的书籍名字:" << endl;
			string new_name;
			cin >> new_name;
			for (auto i = library.begin(); i != library.end();)
			{
				if (i->book_name == b_name)
				{
					i->book_name = new_name;
				}
				else
				{
					i++;
				}
			}
			break;
		}
		case 2:
		{
			cout << "				请输入要修改成的作者名字:" << endl;
			string new_name;
			cin >> new_name;
			for (auto i = library.begin(); i != library.end();)
			{
				if (i->book_name == b_name)
				{
					i->author_name = new_name;
				}
				else
				{
					i++;
				}
			}
			break;
		}
		case 3:
		{
			cout << "				请输入要修改成的编号:" << endl;
			int new_identifier;
			cin >> new_identifier;
			for (auto i = library.begin(); i != library.end();)
			{
				if (i->book_name == b_name)
				{
					i->book_identifier = new_identifier;
				}
				else
				{
					i++;
				}
			}
			break;
		}
		case 4:
		{
			exit_mark = 1;//设置退出标识符
		}
		default:
		{
			cout << "			输入错误" << endl;
			break;
		}
		}
		if (exit_mark == 1)//如果标识到要退出,则直接退出for循环
		{
			break;
		}
	}
}

//显示全部图书功能
void manage::print_all_book()
{
	for (auto i = library.begin(); i != library.end();)
	{
		i->print();//调用其打印函数
		i++;
	}
}

//按书名查找书籍
bool manage::find_book(string book_name_)
{
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_name == book_name_)
		{
			i->print();//调用其打印函数
			mark = 1;
			break;
		}
		else
			i++;
	}
	if (mark == 0)
	{
		cout << "			查无此书" << endl;
		return false;
	}
	return true;
}

//按作家来查找书籍
void manage::find_author(string author)
{
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->author_name == author)
		{
			i->print();//调用其打印函数
			mark = 1;
		}
		else
			i++;
	}
	if (mark == 0)
	{
		cout << "			抱歉,暂无此作家的书籍" << endl;
	}
}

//按图书编号来查找书籍
void manage::find_identifier(int identifier)
{
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_identifier == identifier)
		{
			i->print();//调用其打印函数
			mark = 1;
		}
		else
			i++;
	}
	if (mark == 0)
	{
		cout << "			抱歉,未找到该编号的书籍" << endl;
	}
}

//借阅图书
void manage::borrow_book(string book, int time)
{
	//判断是否有这本书
	if (find_book(book))
	{
		cout << "			你要借阅的是这本书吗?" << endl;
		cout << "			请问确定要借阅这本书吗?" << endl;
		cout << "			确认请输入1,否则输入其他数:" << endl;
		int mark;
		cin >> mark;
		if (mark == 1)
		{
			cout << "			请输入你的姓名:" << endl;
			string name;
			int stud_num;
			cin >> name;
			cout << "			请输入你的学号:" << endl;
			cin >> stud_num;
			student s(name, stud_num);
			int mark2 = 0;//记录是否借出成功
			for (auto i = library.begin(); i != library.end();)
			{
				if (i->book_name == book && i->book_num >= 1)
				{
					i->set_case(-1);//调用其图书状态函数,减去1
					i->set_borrow(s, time);//设置该本书籍借阅者的名字和借出时间
					mark2 = 1;
					cout << "			借出成功,记得按时归还喔" << endl;
					break;
				}
				else
					i++;
			}
			if (mark2 == 0)
			{
				cout << "			借出失败,原因是图书库存不足" << endl;
			}
		}
	}
	//当调用find_book时,自动会在没有找到该书籍时输出"查无此书"
}

//归还图书
void manage::return_book(string book)
{
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_name == book)
		{
			i->set_case(1);//调用其图书状态函数,加上1
			cout << "			归还成功" << endl;
			break;
		}
		else
			i++;
	}
}

