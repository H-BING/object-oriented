
/********************************************************************************
FileName    :           Print.cpp

Author      :           HBING
Version     :           1.0
Date        :           2016/02/21

Description:
         定义Calculation类中的类方法

Function List:
         void ToPrintQueue        输出字符串队列
                                  对不符合要求的数字进行报错

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        实现四则运算表达式的计算

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Print.h"
using namespace std;

void Print::ToPrintQueue(queue<string>q) 
{

	string m_str;//暂时存储字符串

	while (!q.empty()) 
	{

		m_str = q.front();
		//判断数字长度
		if (m_str.size() > 10) 
		{
			cout << "您输入的数字位数超过10位（包括小数位）" << endl;
			break;
		}
		cout << q.front() << endl;
		q.pop();

	}

}