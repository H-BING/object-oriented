
/********************************************************************************
FileName    :           Scan.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/04/10

Description:
         定义Scan类中的类方法

Function List:
         void ToStringQueue        拆分四则运算表达式

History:

<author>    <time>     <version>            <desc>
 HBING    2016/02/21      1.0          拆分四则运算表达式
 HBING    2016/04/10      1.10         1.实现-号前补0以保证算式合法性
                                       2.补充对符号的判断：即 + - * / ( ) 才可入队列
 HBING    2016/04/13      1.11         对数字位数超过10位进行报错

********************************************************************************/

#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string m_sInput) 
{

	string sInput;
	int nInputLength;
	
	for (int i = 0; i <= m_sInput.size(); i++) 
	{

		if (sInput.empty()) 
		{
			sInput = m_sInput[i];
			nInputLength = 1;
		}

		//数字
		if (m_sInput[i] <= '9'&&m_sInput[i] >= '0' || m_sInput[i] == '.') 
		{

			//两位及以上数字
			if ((m_sInput[i + 1] <= '9'&&m_sInput[i + 1] >= '0') || m_sInput[i + 1] == '.') 
			{
				sInput += m_sInput[i + 1];
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

				q.push(sInput);
				sInput.clear();
			}

		}

		//符号
		else if (m_sInput[i] == '+' || m_sInput[i] == '-' || m_sInput[i] == '*' || m_sInput[i] == '/' || m_sInput[i] == '(' || m_sInput[i] == ')')
		{
			//非法运算'-'前补0
			if ((q.empty() || q.back() == "(") && m_sInput[i] == '-')
			{
				q.push("0");
			}
			
			q.push(sInput);
			sInput.clear();
		}
	}

}

