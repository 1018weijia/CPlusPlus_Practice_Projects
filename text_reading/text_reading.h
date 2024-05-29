#pragma once
#include<iostream>
#include<vector>

using namespace std;
//创建一个文本读取类，实现以下的功能
class text_reading
{
public:
	text_reading(string file_where);//构造函数
	text_reading(const text_reading& t);//复制构造函数
	~text_reading();//析构函数
	void PrintSentences();//打印所有的句子，每行打印一个
	void PrintSentencesAscend();// 将所有句子按字典升序排列，重新打印
	void PrintWordCount();// 打印每个单词出现的次数，如the: 36, word : 12
	void PrintTopWordContext(int n);//打印词频最高的n个单词及其出现的次数
	int find_word(string word);//单词查找函数，不存在即返回0，否则返回其个数

private:
	vector<string> sentences;
};