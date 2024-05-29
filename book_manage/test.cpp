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
	manage lib;//��������
	//��ͼ����������鼮,ͨ����ȡ�ļ���ʵ��
	string file_where = "C://Users//22066//Desktop//library.txt";	//���ļ�λ�ø�ֵ�����ݳ�Ա
	//ʵ�ֶ�ȡ�ļ�����
	ifstream f_read;//������ȡ�ļ�����
	string line,word;//�����ı�����
	int line_num = 0;//��ʼ���к�
	f_read.open(file_where);//���ı�
	//��ʼ�������ĸ�ͼ����Ϣֵ
	string b_name = "", b_author = "";
	int b_identifier = 0;
	int num = 0;
	while (getline(f_read, line))//��ʼ���ж�ȡ�ı���line�洢ÿ�е��ı�
	{
		line_num++;//�к�����
		istringstream oneline(line);//����istingstream���󣬺�line��
		oneline >> word;
		if (line_num % 4 == 1)//����Ϊ4,����ǵ�һ��,��Ϊ����
		{
			b_name = word;	
		}
		else if (line_num % 4 == 2)//����ǵڶ���,��Ϊ����
		{
			b_author = word;
		}
		else if (line_num % 4 == 3)//����ǵ�����,���ʾ���
		{
			b_identifier = atoi(word.c_str());
		}
		else //����ǵ�����,���ʾ��������
		{
			num = atoi(word.c_str());//����ת��Ϊ����
			//�������������ʱ,��ʱ���ĸ���Ϣ���Ѿ�������,���Խ��м����鼮����
			book temp(b_name, b_author, b_identifier);
			temp.book_num = temp.book_num + num;
			//�������õ��鼮�����library������
			lib.library.push_back(temp);
		}
	}
	f_read.close();//��ȡ��ϣ��ر��ļ�
	cout << "			��ӭ����ͼ�����ϵͳ:			" << endl;
	cout << "			��ѡ���������:			" << endl;
	cout << "			����Ա������0,ѧ��������1			" << endl;
	int manage_or_student;
	cin >> manage_or_student;
	switch (manage_or_student)
	{
	case 1:
	{
		cout << "			��ӭʹ��ͼ�����ϵͳѧ����			" << endl;
		int is_exit;
		do 
		{
			cout << "			��ѡ������Ҫ�Ĳ���:			" << endl;
			cout << "			����1,	��ѯͼ��			" << endl;
			cout << "			����2,	����ͼ��			" << endl;
			cout << "			����3,	�黹ͼ��			" << endl;
			cout << "			������������,	�˳�ϵͳ			" << endl;
			cin >> is_exit;
			if (is_exit != 1 && is_exit != 2 && is_exit != 3)//�˳�����
			{
				break;
			}
			switch (is_exit)
			{
				//�����鼮,��������������/�����߲���/���鼮��Ų���
			case 1:
			{
				cout << "		" << endl;
				cout << "			��ѡ����Ҫ��ѯ�ķ�ʽ:			" << endl;
				cout << "			����1,	ѡ����������			" << endl;
				cout << "			����0,	ѡ������������			" << endl;
				cout << "			����2,	ѡ��ͼ���Ų���			" << endl;
				int find_way;
				cin >> find_way;
				switch (find_way)
				{
				case 0:
				{
					string author;
					cout << "			������������:			" << endl;
					cin >> author;
					cout << "			���ҽ������:			" << endl;
					lib.find_author(author);
					break;
				}
				case 1:
				{
					string b_name;
					cout << "			����������			" << endl;
					cin >> b_name;
					cout << "			���ҽ������:			" << endl;
					lib.find_book(b_name);
					break;
				}
				case 2 :
				{
					int identifier;
					cout << "			��������			" << endl;
					cin >> identifier;
					cout << "			���ҽ������:			" << endl;
					lib.find_identifier(identifier);
					break;
				}
				default:
					break;
				}
			break;
			}
				//����ͼ��
			case 2:
			{
				cout << "			��������Ҫ���ĵ�ͼ����:			" << endl;
				string b_name;
				cin >> b_name;
				cout << "			��������Ҫ���ĵ�����:			" << endl;
				int times;
				cin >> times;
				lib.borrow_book(b_name,times);
				break;
			}
			//�黹ͼ��
			case 3:
			{
				cout << "			��������Ҫ�黹��ͼ����			" << endl;
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
		cout << "			��ӭʹ��ͼ�����ϵͳ�����			" << endl;
		int is_exit;
		do
		{
			cout << "			��ѡ������Ҫ�Ĳ���:			" << endl;
			cout << "			����1,	����ͼ��			" << endl;
			cout << "			����2,	ɾ��ͼ��			" << endl;
			cout << "			����3,	�޸�ͼ��			" << endl;
			cout << "			����4,	��ʾȫ��ͼ��			" << endl;
			cout << "			����5,	����ͼ��			" << endl;
			cout << "			������������,		�˳�ϵͳ			" << endl;
			cin >> is_exit;
			if (is_exit != 1 && is_exit != 2 && is_exit != 3 && is_exit != 4 && is_exit != 5)
			{
				break;
			}
			switch (is_exit)
			{
				//�����鼮
			case 1:
			{
				cout << "			�밴����ִ��:			" << endl;
				lib.add_book();//���ú�������,���������в�����ʾ
				break;
			}
				//ɾ���鼮
			case 2:
			{
				cout << "			��������Ҫɾ�����鼮:			" << endl;
				string b_name;
				cin >> b_name;
				lib.delete_book(b_name);//��û���Ȿ��ʱ,����Ҳ����ʾ���޴���
				break;
			}
				//�޸��鼮,�˹��������������鼮ʱ�����˹������µ�ͼ����Ϣ���������
			case 3:
			{
				cout << "			�밴������ʾ����:			" << endl;
				lib.set_book();
				break;
			}
				//��ӡȫ���鼮��Ϣ
			case 4:
			{
				cout << "			ȫ��ͼ����Ϣ����:			" << endl;
				lib.print_all_book();
				break;
			}
				//��ѯ�鼮,��ѧ������ͬ
			case 5:
			{
				cout << "			��ѡ����Ҫ��ѯ�ķ�ʽ:			" << endl;
				cout << "			����1,	ѡ����������			" << endl;
				cout << "			����0,	ѡ������������			" << endl;
				cout << "			����2,	ѡ���鼮��Ų���			" << endl;
				int find_way;
				cin >> find_way;
				switch (find_way)
				{
				case 0:
				{
					string author;
					cout << "			������������*			" << endl;
					cin >> author;
					cout << "			���ҽ������:			" << endl;
					lib.find_author(author);
					break;
				}
				case 1:
				{
					string b_name;
					cout << "			����������			" << endl;
					cin >> b_name;
					cout << "			���ҽ������:			" << endl;
					lib.find_book(b_name);
					break;
				}
				case 2:
				{
					int identifier;
					cout << "			��������			" << endl;
					cin >> identifier;
					cout << "			���ҽ������:			" << endl;
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
	cout << "			�����˳�ϵͳ,��лʹ��			" << endl;
	return 0;
}