#include"text_reading.h"
using namespace std;
int main()
{
	cout << "		��ӭʹ���ı���ѯϵͳ" << endl;
	//���û������ļ�λ��
	string file_where = "";
	cout << "		�������ļ����ڵ�λ�ã�ע�⽫��б���滻��'//'�" << endl;
	cin >> file_where;
	//��ȡ�ļ�
	text_reading t1(file_where);
	//functionΪ�������ţ�exit_markΪ�˳���־
	int function = 0,exit_mark = 0;
	cout << "		��������Ӧ���ܱ��ʵ��������Ҫ�Ĳ���" << endl;
	//��������������ʱ���˳�ϵͳ
	while (1)
	{
		cout << "		����1��	��ӡ�ı��е����о���" << endl;
		cout << "		����2��	����ĸ���ӡ�ı��е����о���" << endl;
		cout << "		����3��	��ӡ�ı��е����е��ʳ��ֵ�Ƶ��" << endl;
		cout << "		����4��	�������ӡ�ı���ǰ��λ�ߵĵ���" << endl;
		cout << "		����5��	����ĳ���������ı��г��ֵĴ���" << endl;
		cout << "		�������������˳�ϵͳ" << endl;
		cin >> function;
		switch (function)
		{
			//��ӡ���ӹ���
		case 1:
		{
			t1.PrintSentences();
			cout << endl;
			break;
		}
		//��˳���ӡ���ӹ���
		case 2:
		{
			t1.PrintSentencesAscend();
			cout << endl;
			break;
		}
		//��ӡ���е��ʳ��ֵĴ���
		case 3:
		{
			t1.PrintWordCount();
			cout << endl;
			break;
		}
		//��ӡƵ��ǰnumλ�ĵ���
		case 4:
		{
			int num = 0;
			cout << "		��������Ҫ�õ���ǰnλ������" << endl;
			cin >> num;
			t1.PrintTopWordContext(num);
			cout << endl;
			break;
		}
		//���ҵ�����Ӧ�ĳ��ִ���
		case 5:
		{
			string word = "";
			cout << "		��������Ҫ���ҵĵ��ʣ�" << endl;
			cin >> word;
			cout << word << "���ֵ�Ƶ���ǣ�" << endl;
			cout << t1.find_word(word);
			cout << endl;
			break;
		}
		default:
			exit_mark = 1;//�����˳���־
			break;
		}
		if (exit_mark)
		{
			break;//����˳���־�����ģ����˳�ѭ��
		}
	}
	cout << "�����˳�ϵͳ����лʹ��" << endl;
}