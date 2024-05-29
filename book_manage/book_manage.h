#pragma once
#include"book_infomation.h"
using namespace std;
//ͼ�����ϵͳ,����ͼ����Ϣ����ɾ�޸�,��ͼ�����Աʹ��
class manage
{
public:
	vector<book> library;//����ͼ���vector,����鼮��
public:
	void add_book();//����ͼ�鹦��,��Ҫ�����鼮��ĺ���
	void delete_book(string book_name);//ɾ���鼮����
	void set_book();//�޸��鼮����
	void print_all_book();//��ʾȫ��ͼ�鹦��
	bool find_book(string book_name);//����������ĳ�����Ƿ����,�������ӡ����Ϣ,������ʾ���޴���
	void find_author(string author);//����������������Ʒ
	void find_identifier(int identifier);//������������鼮
	void borrow_book(string book, int time);//����ͼ�飬�Լ�ʱ��
	void return_book(string book);//�黹ͼ��

};

//�����鼮,��������
void manage::add_book()
{
	string b_name, b_author;
	int b_identifier;
	cout << "			�������鼮����:			" << endl;
	cin >> b_name;
	cout << "			�������鼮������:		" << endl;
	cin >> b_author;
	cout << "			�������鼮���:			" << endl;
	cin >> b_identifier;
	book temp(b_name,b_author,b_identifier);
	int add_num;
	cout << "			���������ӵ��鼮����:		" << endl;
	cin >> add_num;
	temp.book_num = temp.book_num + add_num;
	library.push_back(temp);
}

//ɾ���鼮
void manage::delete_book(string book_name_)
{
	//����vector����,����ͬ���鼮
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
		cout << "			���޴���" << endl;
	}
}

//�޸��鼮����
void manage::set_book()
{
	cout << "			��������Ҫ���ĵ��鼮������:" << endl;
	string b_name;
	cin >> b_name;
	//����Ҫ�޸ĵ����ݵ�����func_num,exit_markΪ��ʶ��,�ж��Ƿ�Ҫ�˳��޸�����
	int func_num,exit_mark=0;
	cout << "			������Ҫ�޸ĵ����ݵ�����(1~3):" << endl;
	cin >> func_num;
	for (int time = 0; time < func_num; time++)
	{
		cout << "			��ѡ��Ҫ�޸ĵ�����" << endl;
		cout << "			����1:�޸��鼮����" << endl;
		cout << "			����2:�޸��鼮������" << endl;
		cout << "			����3:�޸��鼮���" << endl;
		cout << "			����4:�˳��޸�" << endl;
		int choose_function;
		cin >> choose_function;
		int false_times = 0;//�����������Ĵ���
		while (choose_function != 1 && choose_function != 2 && choose_function != 3 && choose_function != 4)
		{
			cout << "			�������,����������" << endl;
			false_times++;
			if (false_times == 3)
			{
				break;//�����������ﵽ3��,���˳�����
			}
			cin >> choose_function;
		}
		switch (choose_function)
		{
		case 1:
		{
			cout << "			������Ҫ�޸ĳɵ��鼮����:" << endl;
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
			cout << "				������Ҫ�޸ĳɵ���������:" << endl;
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
			cout << "				������Ҫ�޸ĳɵı��:" << endl;
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
			exit_mark = 1;//�����˳���ʶ��
		}
		default:
		{
			cout << "			�������" << endl;
			break;
		}
		}
		if (exit_mark == 1)//�����ʶ��Ҫ�˳�,��ֱ���˳�forѭ��
		{
			break;
		}
	}
}

//��ʾȫ��ͼ�鹦��
void manage::print_all_book()
{
	for (auto i = library.begin(); i != library.end();)
	{
		i->print();//�������ӡ����
		i++;
	}
}

//�����������鼮
bool manage::find_book(string book_name_)
{
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_name == book_name_)
		{
			i->print();//�������ӡ����
			mark = 1;
			break;
		}
		else
			i++;
	}
	if (mark == 0)
	{
		cout << "			���޴���" << endl;
		return false;
	}
	return true;
}

//�������������鼮
void manage::find_author(string author)
{
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->author_name == author)
		{
			i->print();//�������ӡ����
			mark = 1;
		}
		else
			i++;
	}
	if (mark == 0)
	{
		cout << "			��Ǹ,���޴����ҵ��鼮" << endl;
	}
}

//��ͼ�����������鼮
void manage::find_identifier(int identifier)
{
	int mark = 0;
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_identifier == identifier)
		{
			i->print();//�������ӡ����
			mark = 1;
		}
		else
			i++;
	}
	if (mark == 0)
	{
		cout << "			��Ǹ,δ�ҵ��ñ�ŵ��鼮" << endl;
	}
}

//����ͼ��
void manage::borrow_book(string book, int time)
{
	//�ж��Ƿ����Ȿ��
	if (find_book(book))
	{
		cout << "			��Ҫ���ĵ����Ȿ����?" << endl;
		cout << "			����ȷ��Ҫ�����Ȿ����?" << endl;
		cout << "			ȷ��������1,��������������:" << endl;
		int mark;
		cin >> mark;
		if (mark == 1)
		{
			cout << "			�������������:" << endl;
			string name;
			int stud_num;
			cin >> name;
			cout << "			���������ѧ��:" << endl;
			cin >> stud_num;
			student s(name, stud_num);
			int mark2 = 0;//��¼�Ƿ����ɹ�
			for (auto i = library.begin(); i != library.end();)
			{
				if (i->book_name == book && i->book_num >= 1)
				{
					i->set_case(-1);//������ͼ��״̬����,��ȥ1
					i->set_borrow(s, time);//���øñ��鼮�����ߵ����ֺͽ��ʱ��
					mark2 = 1;
					cout << "			����ɹ�,�ǵð�ʱ�黹�" << endl;
					break;
				}
				else
					i++;
			}
			if (mark2 == 0)
			{
				cout << "			���ʧ��,ԭ����ͼ���治��" << endl;
			}
		}
	}
	//������find_bookʱ,�Զ�����û���ҵ����鼮ʱ���"���޴���"
}

//�黹ͼ��
void manage::return_book(string book)
{
	for (auto i = library.begin(); i != library.end();)
	{
		if (i->book_name == book)
		{
			i->set_case(1);//������ͼ��״̬����,����1
			cout << "			�黹�ɹ�" << endl;
			break;
		}
		else
			i++;
	}
}

