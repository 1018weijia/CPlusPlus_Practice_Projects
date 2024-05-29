#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"student.h"
using namespace std;
//���ͼ���࣬����ͼ�����Ϣ
class book
{
//���ݲ���
public:
	string book_name = "";//ͼ�������
	int book_identifier = 0;//ͼ��ı��
	string author_name = "";//���ߵ�����
	int book_case = 0;//����ͼ��״̬,1���ڼ�,0���Ѿ�ȫ�����
	int book_num = 0;//���ø�ͼ��Ŀ������,���ÿ����Ϊ0ʱ,book_case����ֵ���Ϊ0
	map<student,int> borrowers;//�洢��ͼ�����ߵ�����
//��������
public:
	book(string book_name,string book_author,int book_identifier);//���캯��
	void set_name(string book_name_);//����ͼ������,ͼ�����Աϵͳʹ��
	void set_identifier(int identifier);//����ͼ����,ͼ�����Աϵͳʹ��
	void set_author(string name);//����ͼ�����������,ͼ�����Աϵͳʹ��
	void set_case(int bor_num);//����ͼ���״̬,bor_numΪ���/���ص�����,���ڸı�book_num��book_case
	void set_borrow(student stud,int time);//���ø�ͼ�����ߵ�����,���ֺͽ��ʱ��,ʹ��map��������
	void print();//��ӡ��ͼ�����Ϣ
	bool operator < (const book& b) const;//����С�ں������
};

//����ʵ��

//���캯��
book::book(string book_name_, string book_author, int book_identifier_)
{
	this->book_name = book_name_;
	this->book_identifier = book_identifier_;
	this->author_name = book_author;

}


//����ͼ������,ͼ�����Աʹ��
void book::set_name(string book_name_)
{
	this->book_name = book_name_;
}

//����ͼ����,ͼ�����Աʹ��
void book::set_identifier(int identifier)
{
	this->book_identifier = identifier;
}

//����ͼ�����������,ͼ�����Աʹ��
void book::set_author(string name)
{
	this->author_name = name;
}

//����ͼ���״̬,bor_numΪ���/���ص�����,ͼ�����Աʹ��
void book::set_case(int bor_num)
{
	if (bor_num < 0)//���Ҫ������������ڿ������,��Ҫ˵��������
	{
		if (-(bor_num) > this->book_num)
			cout << "			�鼮��治��" << endl;
		else
		{
			cout << "			����ɹ�" << endl;
			this->book_num = this->book_num + bor_num;//����ֱ�Ӽ������־���,���ֿ����ɸ�
		}
			
	}
	else
	{

		cout << "			���Ӹ�ͼ��" << bor_num <<"��" << endl;
		this->book_num = this->book_num + bor_num;
	}
}

//���ø�ͼ�����ߵ�����,���ֺͽ��ʱ��,ʹ��map��������
void book::set_borrow(student stud, int time)
{
	this->borrowers[stud] = time;
}

//��ӡͼ����Ϣ
void book::print()
{
	cout << "			����:" << this->book_name << endl;
	cout << "			������:" << this->author_name << endl;
	cout << "			ͼ����:" << this->book_identifier << endl;
	cout << "			ͼ�����:" << this->book_num << endl;
}

//����С�ں������
bool book::operator <(const book& b) const
{
	if (this->book_identifier < b.book_identifier)
		return true;
	else
		return false;
}
