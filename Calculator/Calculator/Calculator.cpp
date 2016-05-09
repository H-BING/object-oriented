
/********************************************************************************
FileName    :           Calculator.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/02/21

Description:
         计算带括号的四则运算表达式：
             1、直接输出最终数值
             2、输入"-a"时写出完整表达式
			 3、输入"-f"时用文件读取数据并在文件中输出最终结果

Function List:
         int main()                               主体代码
		 void ToDrawOperationInterface()          绘制操作指南

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        实现四则运算表达式的拆卸
 HBING    2016/04/10      1.1        实现四则运算表达式的计算
 HBING    2016/05/08      1.2        增加输入方式，并按不同要求输出结果

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Print.h"
using namespace std;

//绘制操作指南
void ToDrawOperationInterface()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	cout << "    一. 注意事项：" << endl;
	cout << "        1. 请输入合法四则运算表达式" << endl;
	cout << "        2. 输入的数字位数不超过10位（包括小数位）" << endl;
	cout << "        3. 计算结果保留小数点后三位" << endl;
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	cout << "    二. 输入输出方式：" << endl;
	cout << "        用X代表第一个参数，用Y代表第二个参数，用Z代表第三个参数" << endl;
	cout << "        1. X为表达式，Y、Z为空。只输出计算结果。" << endl;
	cout << "        2. X为“-a”，Y为表达式，Z为空。输出完整表达式。" << endl;
	cout << "        3. X为“-f”，Y、Z为txt文件的路径。" << endl;
	cout << "           从Y路径中读取表达式，将答案输出到Z路径上。" << endl;
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
}

//主函数
int main(int argc, char* argv[])
{
	//绘制操作指南
	ToDrawOperationInterface();

	string sInput;
	bool bIs_a = false;//标记是否输入-a

	Print print;
	string text_txt, result_txt;

	int i;
	for (i = 1; i < argc; i++) 
	{
		sInput = argv[i];

		//标记为-a方式输出
		if (sInput == "-a") 
		{
			bIs_a = !bIs_a;
		}
		//以文件输出
		else if (sInput == "-f") 
		{
			text_txt = argv[++i];
			result_txt = argv[++i];

			print.ToPrintIs_f(text_txt, result_txt);
		}
		//以非文件输出
		else 
		{
			print.ToPrintIsNot_f(sInput, bIs_a);
		}
		
		sInput.clear();
	}
	
	return 0;
}