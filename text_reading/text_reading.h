#pragma once
#include<iostream>
#include<vector>

using namespace std;
//����һ���ı���ȡ�࣬ʵ�����µĹ���
class text_reading
{
public:
	text_reading(string file_where);//���캯��
	text_reading(const text_reading& t);//���ƹ��캯��
	~text_reading();//��������
	void PrintSentences();//��ӡ���еľ��ӣ�ÿ�д�ӡһ��
	void PrintSentencesAscend();// �����о��Ӱ��ֵ��������У����´�ӡ
	void PrintWordCount();// ��ӡÿ�����ʳ��ֵĴ�������the: 36, word : 12
	void PrintTopWordContext(int n);//��ӡ��Ƶ��ߵ�n�����ʼ�����ֵĴ���
	int find_word(string word);//���ʲ��Һ����������ڼ�����0�����򷵻������

private:
	vector<string> sentences;
};