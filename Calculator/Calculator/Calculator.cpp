
/********************************************************************************
FileName    :           Calculator.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/02/21

Description:
         计算带括号的四则运算表达式：
             1、直接输出最终数值
             2、输入"-a"时写出完整表达式

Function List:
         int main()      主体代码

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        实现四则运算表达式的拆卸
 HBING    2016/04/10      1.1        实现四则运算表达式的计算

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;


int main(int argc, char* argv[])
{
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
	cout << "    注意事项：" << endl;
	cout << "        1、请输入合法四则运算表达式" << endl;
	cout << "        2、输入的数字位数不超过10位（包括小数位）" << endl;
	cout << "        3、计算结果最终保留三位小数" << endl;
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl << "请输入四则运算表达式：" << endl;
	string input;
	int temp = 0;//标记是否输入"-a"
	
	
	int i;
	for (i = 1; i < argc; i++) 
	{
		
		input = argv[i];

		Scan scan;
		//Print print;
		Calculation calculate;

		if(input=="-a")
		{
			temp = 1;
			continue;
		}

		if (temp == 1) 
		{
			cout << input << "= ";
		}

		//拆分表达式
		scan.ToStringQueue(input);

		/*
		//调用并输出拆分好的队列
		print.ToPrintQueue(scan.q);
		*/

		//计算表达式的值
		calculate.ToCalculate(scan.q);

		input.clear();
	}
	
	return 0;
}