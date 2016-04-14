
/********************************************************************************
FileName    :           Scan.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/04/10

Description:
         定义Scan类中的类方发

Function List:
         void ToStringQueue        拆分四则运算表达式

History:

<author>    <time>     <version>            <desc>
 HBING    2016/02/21      1.0          拆分四则运算表达式
 HBING    2016/04/10      1.10         实现-号前补0以保证算式合法性
                                       补充对符号的判断：即 + - * / ( ) 才可入队列
 HBING    2016/04/13      1.11         对数字位数超过10位进行报错

********************************************************************************/

#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string input) 
{

	string m_strInput;
	int nInputLength;
	
	for (int i = 0; i <= input.size(); i++) 
	{

		if (m_strInput.empty()) 
		{
			m_strInput = input[i];
			nInputLength = 1;
		}

		//数字
		if (input[i] <= '9'&&input[i] >= '0' || input[i] == '.') 
		{

			//两位及以上数字
			if ((input[i + 1] <= '9'&&input[i + 1] >= '0') || input[i + 1] == '.') 
			{
				m_strInput += input[i + 1];
				nInputLength++;
			}

			//一位数字
			else 
			{
				//数字位数超过10位报错
				if (nInputLength > 10) 
				{
					cout << "您输入的数字位数超过10位（包括小数位）" << endl;
					exit(0);
				}

				q.push(m_strInput);
				m_strInput.clear();
			}

		}

		//符号
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')
		{
			//非法运算'-'前补0
			if ((q.empty() || q.back() == "(") && input[i] == '-')
			{
				q.push("0");
			}
			
			q.push(m_strInput);
			m_strInput.clear();
		}
	}

}

