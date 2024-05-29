#include"text_reading.h"
using namespace std;
#include<vector>
#include<fstream>
#include <algorithm>

//构造函数,以文件名为形参，读入该文件的内容
text_reading::text_reading(string file_where)
{
	fstream file;
	file.open(file_where, ios::in);
	char c;
	file >> noskipws;//避免符号被直接忽略
	string sentence;
	while (!file.eof())//当未读到文件末尾时，继续循环
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
		sentence += c;//加上符号
		file >> c;  //连接符号后紧随的空格
		sentences.push_back(sentence);
	}
	file.close();
}
//复制构造函数
text_reading::text_reading(const text_reading & t)
{
	this->sentences = t.sentences;
}
//析构函数
text_reading::~text_reading()
{
	this->sentences.clear();//清空数据
}
//打印所有的句子
void text_reading::PrintSentences()
{
	//遍历vector即可
	cout << "输出所有句子(无顺序)" << endl;
	for (auto i = sentences.begin(); i != sentences.end(); i++)
	{
		cout << *i << endl;
	}
}
//将所有句子按字典升序排列，重新打印
void text_reading::PrintSentencesAscend()
{
	vector<string> sort_sentences = sentences;//复制一个副本
	//按字典序升序排列
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
	cout << "输出所有句子(有顺序)" << endl;
	for (auto i = sort_sentences.begin(); i != sort_sentences.end(); i++)
	{
		cout << *i << endl;
	}
}
//打印单词出现的次数
void text_reading::PrintWordCount()
{
	//定义单重集合和多重集和，多重集合用于计数
	vector<string> word_single_set, words_multiple_set;
	for (auto i = sentences.begin(); i != sentences.end(); i++)
	{
		for (int j = 0; j < (*i).size();)
		{
			string word;
			char c = (*i)[j++];
			while (isalpha(c))//当该字符是字母时
			{
				word += c;
				c = (*i)[j++];
			}
			if (word.size() != 0)
			{
				words_multiple_set.push_back(word);//加入多重集
				//如果这个单词不在多重集中出现过，就加入单重集
				if (count(word_single_set.begin(), word_single_set.end(), word) == 0)
					word_single_set.push_back(word);
			}
		}
	}
	cout << "现在输出所有单词的出现次数" << endl;
	for (auto i = word_single_set.begin(); i != word_single_set.end(); i++)
	{
		int num = 0;
		cout << *i << ":";
		num = count(words_multiple_set.begin(), words_multiple_set.end(), (*i));//计数
		cout << num << ";" << endl;
	}
}
//打印词频最高的n个单词
void text_reading::PrintTopWordContext(int n)
{
	//只需复制PrintWordCount中的操作即可
	vector<std::string> words_single_set, words_multiple_set;
	vector<int> nums_count;//每个单词出现的次数数组
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

	//将单重集中的单词的次数存入数组中
	for (auto i = words_single_set.begin(); i != words_single_set.end(); i++)
	{
		int num;
		num = count(words_multiple_set.begin(), words_multiple_set.end(), (*i));
		nums_count.push_back(num);
	}
	//排序
	sort(nums_count.begin(), nums_count.end(), greater<int>());
	cout << "出现单词频率最高的前" << n << "位是：" << endl;
	//如果n大于单词个数，则将n赋值为单词个数
	if (n > words_single_set.size())
	{
		cout << "输入个数超过单词个数，将输出所有的单词出现频数:" << endl;
		n = words_single_set.size();
	}
	for (auto i = words_single_set.begin(); i != words_single_set.end(); i++)
	{
		int num;
		num = count(words_multiple_set.begin(), words_multiple_set.end(), (*i));
		//依据形参n的数据，决定输出前几位的数据
		for (auto j = nums_count.begin(); j != nums_count.begin() + n; j++)
		{
			if (num == *j)
				cout << *i << ":" << num << endl;
		}
	}
}

//输出该单词出现的频率
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
