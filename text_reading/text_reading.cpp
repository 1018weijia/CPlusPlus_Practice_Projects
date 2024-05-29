#include"text_reading.h"
using namespace std;
#include<vector>
#include<fstream>
#include <algorithm>

//���캯��,���ļ���Ϊ�βΣ�������ļ�������
text_reading::text_reading(string file_where)
{
	fstream file;
	file.open(file_where, ios::in);
	char c;
	file >> noskipws;//������ű�ֱ�Ӻ���
	string sentence;
	while (!file.eof())//��δ�����ļ�ĩβʱ������ѭ��
	{
		sentence = "";
		file >> c;
		while (c != ',' && c != '.' && !file.eof())
		{
			if (c != '\n')
			{
				sentence += c;
			}
			file >> c;
		}
		sentence += c;//���Ϸ���
		file >> c;  //���ӷ��ź����Ŀո�
		sentences.push_back(sentence);
	}
	file.close();
}
//���ƹ��캯��
text_reading::text_reading(const text_reading & t)
{
	this->sentences = t.sentences;
}
//��������
text_reading::~text_reading()
{
	this->sentences.clear();//�������
}
//��ӡ���еľ���
void text_reading::PrintSentences()
{
	//����vector����
	cout << "������о���(��˳��)" << endl;
	for (auto i = sentences.begin(); i != sentences.end(); i++)
	{
		cout << *i << endl;
	}
}
//�����о��Ӱ��ֵ��������У����´�ӡ
void text_reading::PrintSentencesAscend()
{
	vector<string> sort_sentences = sentences;//����һ������
	//���ֵ�����������
	for (auto i = sort_sentences.end() - 1; i > sort_sentences.begin(); i--)
	{
		for (auto j = sort_sentences.begin(); j < i; j++)
		{
			if (*j > *(j + 1))
			{
				string r = *j;
				*j = *(j + 1);
				*(j + 1) = r;
			}
		}
	}
	cout << "������о���(��˳��)" << endl;
	for (auto i = sort_sentences.begin(); i != sort_sentences.end(); i++)
	{
		cout << *i << endl;
	}
}
//��ӡ���ʳ��ֵĴ���
void text_reading::PrintWordCount()
{
	//���嵥�ؼ��ϺͶ��ؼ��ͣ����ؼ������ڼ���
	vector<string> word_single_set, words_multiple_set;
	for (auto i = sentences.begin(); i != sentences.end(); i++)
	{
		for (int j = 0; j < (*i).size();)
		{
			string word;
			char c = (*i)[j++];
			while (isalpha(c))//�����ַ�����ĸʱ
			{
				word += c;
				c = (*i)[j++];
			}
			if (word.size() != 0)
			{
				words_multiple_set.push_back(word);//������ؼ�
				//���������ʲ��ڶ��ؼ��г��ֹ����ͼ��뵥�ؼ�
				if (count(word_single_set.begin(), word_single_set.end(), word) == 0)
					word_single_set.push_back(word);
			}
		}
	}
	cout << "����������е��ʵĳ��ִ���" << endl;
	for (auto i = word_single_set.begin(); i != word_single_set.end(); i++)
	{
		int num = 0;
		cout << *i << ":";
		num = count(words_multiple_set.begin(), words_multiple_set.end(), (*i));//����
		cout << num << ";" << endl;
	}
}
//��ӡ��Ƶ��ߵ�n������
void text_reading::PrintTopWordContext(int n)
{
	//ֻ�踴��PrintWordCount�еĲ�������
	vector<std::string> words_single_set, words_multiple_set;
	vector<int> nums_count;//ÿ�����ʳ��ֵĴ�������
	for (auto i = sentences.begin(); i != sentences.end(); i++)
	{
		for (int j = 0; j < (*i).size();)
		{
			string word;
			char c = (*i)[j++];
			while (isalpha(c))
			{
				word += c;
				c = (*i)[j++];
			}
			if (word.size() != 0)
			{
				words_multiple_set.push_back(word);
				if (count(words_single_set.begin(), words_single_set.end(), word) == 0)
					words_single_set.push_back(word);
			}
		}
	}

	//�����ؼ��еĵ��ʵĴ�������������
	for (auto i = words_single_set.begin(); i != words_single_set.end(); i++)
	{
		int num;
		num = count(words_multiple_set.begin(), words_multiple_set.end(), (*i));
		nums_count.push_back(num);
	}
	//����
	sort(nums_count.begin(), nums_count.end(), greater<int>());
	cout << "���ֵ���Ƶ����ߵ�ǰ" << n << "λ�ǣ�" << endl;
	//���n���ڵ��ʸ�������n��ֵΪ���ʸ���
	if (n > words_single_set.size())
	{
		cout << "��������������ʸ�������������еĵ��ʳ���Ƶ��:" << endl;
		n = words_single_set.size();
	}
	for (auto i = words_single_set.begin(); i != words_single_set.end(); i++)
	{
		int num;
		num = count(words_multiple_set.begin(), words_multiple_set.end(), (*i));
		//�����β�n�����ݣ��������ǰ��λ������
		for (auto j = nums_count.begin(); j != nums_count.begin() + n; j++)
		{
			if (num == *j)
				cout << *i << ":" << num << endl;
		}
	}
}

//����õ��ʳ��ֵ�Ƶ��
int text_reading::find_word(string findword)
{
	int num = 0;
	for (auto i = sentences.begin(); i != sentences.end(); i++)
	{
		for (int j = 0; j < (*i).size();)
		{
			string word;
			char c = (*i)[j++];
			while (isalpha(c))
			{
				word += c;
				c = (*i)[j++];
			}
			if (word == findword)
				num++;
		}
	}
	return num;
}
