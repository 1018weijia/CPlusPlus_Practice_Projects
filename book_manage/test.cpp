#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include"student.h"
#include"book_infomation.h"
#include"book_manage.h";

using namespace std;

int main()
{
	manage lib;//创建对象
	//往图书馆中增加书籍,通过读取文件来实现
	string file_where = "C://Users//22066//Desktop//library.txt";	//将文件位置赋值给数据成员
	//实现读取文件操作
	ifstream f_read;//创建读取文件对象
	string line,word;//定义文本的行
	int line_num = 0;//初始化行号
	f_read.open(file_where);//打开文本
	//初始化定义四个图书信息值
	string b_name = "", b_author = "";
	int b_identifier = 0;
	int num = 0;
	while (getline(f_read, line))//开始按行读取文本，line存储每行的文本
	{
		line_num++;//行号增加
		istringstream oneline(line);//创建istingstream对象，和line绑定
		oneline >> word;
		if (line_num % 4 == 1)//周期为4,如果是第一行,则为书名
		{
			b_name = word;	
		}
		else if (line_num % 4 == 2)//如果是第二行,则为作者
		{
			b_author = word;
		}
		else if (line_num % 4 == 3)//如果是第三行,则表示编号
		{
			b_identifier = atoi(word.c_str());
		}
		else //如果是第四行,则表示存入数量
		{
			num = atoi(word.c_str());//将其转化为数字
			//当进入这个条件时,此时的四个信息都已经被覆盖,可以进行加入书籍操作
			book temp(b_name, b_author, b_identifier);
			temp.book_num = temp.book_num + num;
			//将创建好的书籍类加入library数组中
			lib.library.push_back(temp);
		}
	}
	f_read.close();//读取完毕，关闭文件
	cout << "			欢迎进入图书管理系统:			" << endl;
	cout << "			请选择您的身份:			" << endl;
	cout << "			管理员请输入0,学生请输入1			" << endl;
	int manage_or_student;
	cin >> manage_or_student;
	switch (manage_or_student)
	{
	case 1:
	{
		cout << "			欢迎使用图书管理系统学生端			" << endl;
		int is_exit;
		do 
		{
			cout << "			请选择你需要的操作:			" << endl;
			cout << "			输入1,	查询图书			" << endl;
			cout << "			输入2,	借阅图书			" << endl;
			cout << "			输入3,	归还图书			" << endl;
			cout << "			输入其他数字,	退出系统			" << endl;
			cin >> is_exit;
			if (is_exit != 1 && is_exit != 2 && is_exit != 3)//退出操作
			{
				break;
			}
			switch (is_exit)
			{
				//查找书籍,包括按书名查找/按作者查找/按书籍编号查找
			case 1:
			{
				cout << "		" << endl;
				cout << "			请选择你要查询的方式:			" << endl;
				cout << "			输入1,	选择按书名查找			" << endl;
				cout << "			输入0,	选择按作者名查找			" << endl;
				cout << "			输入2,	选择按图书编号查找			" << endl;
				int find_way;
				cin >> find_way;
				switch (find_way)
				{
				case 0:
				{
					string author;
					cout << "			请输入作者名:			" << endl;
					cin >> author;
					cout << "			查找结果如下:			" << endl;
					lib.find_author(author);
					break;
				}
				case 1:
				{
					string b_name;
					cout << "			请输入书名			" << endl;
					cin >> b_name;
					cout << "			查找结果如下:			" << endl;
					lib.find_book(b_name);
					break;
				}
				case 2 :
				{
					int identifier;
					cout << "			请输入编号			" << endl;
					cin >> identifier;
					cout << "			查找结果如下:			" << endl;
					lib.find_identifier(identifier);
					break;
				}
				default:
					break;
				}
			break;
			}
				//借阅图书
			case 2:
			{
				cout << "			请输入你要借阅的图书名:			" << endl;
				string b_name;
				cin >> b_name;
				cout << "			请输入你要借阅的天数:			" << endl;
				int times;
				cin >> times;
				lib.borrow_book(b_name,times);
				break;
			}
			//归还图书
			case 3:
			{
				cout << "			请输入你要归还的图书名			" << endl;
				string b_name;
				cin >> b_name;
				lib.return_book(b_name);
				break;
			}
			default:
				break;
			}
		} while (is_exit);
	break;
	}
	case 0:
	{
		cout << "			欢迎使用图书管理系统管理端			" << endl;
		int is_exit;
		do
		{
			cout << "			请选择你需要的操作:			" << endl;
			cout << "			输入1,	加入图书			" << endl;
			cout << "			输入2,	删除图书			" << endl;
			cout << "			输入3,	修改图书			" << endl;
			cout << "			输入4,	显示全部图书			" << endl;
			cout << "			输入5,	查找图书			" << endl;
			cout << "			输入其他数字,		退出系统			" << endl;
			cin >> is_exit;
			if (is_exit != 1 && is_exit != 2 && is_exit != 3 && is_exit != 4 && is_exit != 5)
			{
				break;
			}
			switch (is_exit)
			{
				//加入书籍
			case 1:
			{
				cout << "			请按操作执行:			" << endl;
				lib.add_book();//调用函数即可,函数体内有操作提示
				break;
			}
				//删除书籍
			case 2:
			{
				cout << "			请输入你要删除的书籍:			" << endl;
				string b_name;
				cin >> b_name;
				lib.delete_book(b_name);//当没有这本书时,函数也会显示查无此书
				break;
			}
				//修改书籍,此功能用于在增加书籍时由于人工错误导致的图书信息错误的修正
			case 3:
			{
				cout << "			请按操作提示进行:			" << endl;
				lib.set_book();
				break;
			}
				//打印全部书籍信息
			case 4:
			{
				cout << "			全部图书信息如下:			" << endl;
				lib.print_all_book();
				break;
			}
				//查询书籍,和学生端相同
			case 5:
			{
				cout << "			请选择你要查询的方式:			" << endl;
				cout << "			输入1,	选择按书名查找			" << endl;
				cout << "			输入0,	选择按作者名查找			" << endl;
				cout << "			输入2,	选择按书籍编号查找			" << endl;
				int find_way;
				cin >> find_way;
				switch (find_way)
				{
				case 0:
				{
					string author;
					cout << "			请输入作者名*			" << endl;
					cin >> author;
					cout << "			查找结果如下:			" << endl;
					lib.find_author(author);
					break;
				}
				case 1:
				{
					string b_name;
					cout << "			请输入书名			" << endl;
					cin >> b_name;
					cout << "			查找结果如下:			" << endl;
					lib.find_book(b_name);
					break;
				}
				case 2:
				{
					int identifier;
					cout << "			请输入编号			" << endl;
					cin >> identifier;
					cout << "			查找结果如下:			" << endl;
					lib.find_identifier(identifier);
					break;
				}
				default:
					break;
				}
			break;
			}
			default:
				break;
			}
		} while (is_exit);
	break;
	}
	default:
		break;
	}
	cout << "			你已退出系统,感谢使用			" << endl;
	return 0;
}