
/********************************************************************************
FileName    :           Print.cpp

Author      :           HBING
Version     :           1.0
Date        :           2016/02/21

Description:
         定义Calculation类中的类方法

Function List:
         void ToPrintQueue        1.输出字符串队列
                                  2.对不符合要求的数字进行报错
		 void ToPrintIsNot_f      以非文件方式输出结果
		 void ToPrintIs_f         以文件方式输出结果

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        实现对四则运算表达式的拆分结果的输出
 HBING    2016/05/08      1.1        按不同输入输出要求以相应方式输出最终结果

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <fstream>

#include "Scan.h"
#include "Print.h"
#include "Calculation.h"

using namespace std;

//以非文件方式输出结果
void Print::ToPrintIsNot_f(string sInput, bool bIs_a)
{
	Scan scan;
	Calculation calculate;

	//拆分表达式
	scan.ToStringQueue(sInput);

	//计算表达式的值
	calculate.ToCalculate(scan.q);

	if (bIs_a)
	{
		cout << sInput << "= ";
	}
	cout << calculate.m_dResult << endl;
}

//以文件方式输出结果
void Print::ToPrintIs_f(string sText_txt, string sResult_txt) 
{
	
	ifstream in;
	ofstream out;

	//打开文件
	in.open(sText_txt.c_str(), ios::in);
	out.open(sResult_txt.c_str(), ios::out);
	
	while (!in.eof())
	{
		Scan scan;
		Calculation calculate;
		string sExperssion;
		
		//从sText_txt路径获取数据
		getline(in, sExperssion, '\n');

		//拆分表达式
		scan.ToStringQueue(sExperssion);

		
		//计算表达式的值
		calculate.ToCalculate(scan.q);

		//在sResult_txt路径下输出结果
		out << calculate.m_dResult << endl;
	}

	//关闭文件
	in.close();
	out.close();
}

void Print::ToPrintQueue(queue<string>q) 
{

	string m_sStr;//暂时存储字符串

	while (!q.empty()) 
	{
		m_sStr = q.front();

		//判断数字长度
		if (m_sStr.size() > 10) 
		{
			cout << "您输入的数字位数超过10位（包括小数位）" << endl;
			break;
		}
		cout << q.front() << endl;

		q.pop();
	}

}