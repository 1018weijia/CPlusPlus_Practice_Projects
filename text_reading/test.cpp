#include"text_reading.h"
using namespace std;
int main()
{
	cout << "		欢迎使用文本查询系统" << endl;
	//由用户输入文件位置
	string file_where = "";
	cout << "		请输入文件所在的位置，注意将右斜杠替换成'//'喔" << endl;
	cin >> file_where;
	//读取文件
	text_reading t1(file_where);
	//function为操作代号，exit_mark为退出标志
	int function = 0,exit_mark = 0;
	cout << "		请输入相应功能编号实现你所需要的操作" << endl;
	//当输入其他数字时才退出系统
	while (1)
	{
		cout << "		输入1，	打印文本中的所有句子" << endl;
		cout << "		输入2，	按字母序打印文本中的所有句子" << endl;
		cout << "		输入3，	打印文本中的所有单词出现的频数" << endl;
		cout << "		输入4，	按需求打印文本中前几位高的单词" << endl;
		cout << "		输入5，	查找某个单词在文本中出现的次数" << endl;
		cout << "		输入其他数字退出系统" << endl;
		cin >> function;
		switch (function)
		{
			//打印句子功能
		case 1:
		{
			t1.PrintSentences();
			cout << endl;
			break;
		}
		//按顺序打印句子功能
		case 2:
		{
			t1.PrintSentencesAscend();
			cout << endl;
			break;
		}
		//打印所有单词出现的次数
		case 3:
		{
			t1.PrintWordCount();
			cout << endl;
			break;
		}
		//打印频率前num位的单词
		case 4:
		{
			int num = 0;
			cout << "		请输入需要得到的前n位的数据" << endl;
			cin >> num;
			t1.PrintTopWordContext(num);
			cout << endl;
			break;
		}
		//查找单词相应的出现次数
		case 5:
		{
			string word = "";
			cout << "		请输入想要查找的单词：" << endl;
			cin >> word;
			cout << word << "出现的频率是：" << endl;
			cout << t1.find_word(word);
			cout << endl;
			break;
		}
		default:
			exit_mark = 1;//设置退出标志
			break;
		}
		if (exit_mark)
		{
			break;//如果退出标志符更改，则退出循环
		}
	}
	cout << "您已退出系统，感谢使用" << endl;
}