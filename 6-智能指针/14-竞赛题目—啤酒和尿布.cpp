#include <iostream>
#include <string>
#include<algorithm>
#include <map>
#include <vector>
using namespace std;
bool char_compare(char &a, char &b) //bool char_compare函数用于比较字符之间大小
{
	int aa = a;
	int bb = b;
	return aa < bb;
}
int main()
{
	map<string, vector<char> >pdd; //定义一个map容器，key值为string，待输入，value为vector<char>，用于存储多个单字符
	string sca1;//输入sca1值 （sca1->scanf_one)下文同
	do//思考了一下，do——while语法可以先进入运行一次，用与此比 for语法 更合适
	{
		cin >> sca1;
		if (sca1 != "00000")
		{
			int record_num = sca1.size(); //record_num用于记录sca1的长度，运用string 里面的size函数
			for (int i = 0; i < record_num; i++)
				pdd[sca1].push_back(sca1[i]);//将sca1里面的逐个字符输入vector<char>中，运用vector类里面的push_back函数
		}
	} while (sca1 != "00000"); //结束条件
//	cout<<char_compare('a','b');//测试char_compare是否正确
	map<string, vector<char> >::iterator it; //创立map迭代器

	for (it = pdd.begin(); it != pdd.end(); it++) //迭代循环
	{
		sort((it->second).begin(), (it->second).end(), char_compare); //sort函数用于将每一个vector排序，it->second代表取map value值，即vector
		(it->second).erase(unique((it->second).begin(), (it->second).end()), (it->second).end()); //删除掉每一个vector中相同元素们只保留一个
		//unque将vector的重复元素放在尾部，并返回重复部分首地址，erase删除其中部分
	}
//	for(it=pdd.begin();it!=pdd.end();it++)
//	{
//		vector<char>::iterator it2;
//		for(it2=(it->second).begin();it2!=(it->second).end();it2++)
//		cout<<*it2<<' ';
//		cout<<endl;
//	}
//以上注释部分用于输出每个vector排序，去重后的元素，代码正确可以使用
//	string judge_differ;//初代想法是利用字符串找到相邻双字符重复的部分，后来发现输出双字符时相同者并非连贯输出 思路破产
	map<string, int> calculate; //第二个map类，前面储存的key值用于储存一个两个字符构成的字符串，value用于记录相同字符串出现频率
	for (it = pdd.begin(); it != pdd.end(); it++)
	{
		vector<char>::iterator it2, it3; //两个迭代器，用于取尽两个字符组成的字符串
		for (it2 = (it->second).begin(); it2 != (it->second).end(); it2++)
		{
			for (it3 = (it->second).begin(); it3 != it2; it3++) //遍历it2以前的所有元素
			{
				string sca2;//组成字符串，成为不同键值
				if (*it3 < *it2)
				{
					sca2 += *it3;
					sca2 += *it2; //+=可以用于将char连入string
				}
				else
				{
					sca2 += *it2;
					sca2 += *it3;
				}
				//上述函数用于将两个字符从小到大排序，因为购物商品具有无序性
//			if(sca2!=judge_differ)
//			{
//			cout<<sca2<<" ";
				calculate[sca2]++;//将对应的value值增加
//			judge_differ=sca2;
//			}//注释部分为破产思路详细代码
			}
		}
	}
	map<string, int>::iterator it4; //此类map迭代器
	int jud = 0;
	string key; //用于下文最终输出商品相关性输出
	for (it4 = calculate.begin(); it4 != calculate.end(); it4++) //遍历calculate容器
	{
		if ((it4->second) > jud)
		{
			jud = it4->second; //更新jud值，循环判断
			key = it4->first; //保证key为最大value值对应的key值
		}
	}
	cout << key;
	return 0;
}