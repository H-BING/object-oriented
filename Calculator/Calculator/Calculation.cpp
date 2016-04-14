
/********************************************************************************
FileName    :           Calculatoion.cpp

Author      :           HBING
Version     :           1.0
Date        :           2016/04/10

Description:
         定义Calculation类中的类方法

Function List:
         void ToCalculate          实现带括号的四则运算表达式的计算
         int operate_priority      判断符号优先级
         double calculate          + - * / 简单计算

History:

<author>    <time>     <version >            <desc>
 HBING    2016/04/10      1.0        实现四则运算表达式的计算
 HBING    2016/04/10      1.01       改进括号处理

 ********************************************************************************/

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include "Calculation.h"
#include <stdio.h>
using namespace std;

void Calculation::ToCalculate(queue<string>q)
{
	//判断符号优先级
	int operate_priority(char c);

	// + - * / 计算
	double calculate(char oper, double front, double behind);

	double _figure;//暂存中间计算结果
	string m_strQue;//暂存队列元素
	stringstream stream;

	//数字符号分别入stack
	while (!q.empty()) 
	{
		m_strQue = q.front();

		//符号
		if (m_strQue[0] < '0' || m_strQue[0] > '9')
		{
			stream << m_strQue;
			stream >> m_cTemp;

			operate.push(m_cTemp);
			stream.clear();
		}

		//数字
		else
		{
			stream << m_strQue;
			stream >> m_dTemp;

			figure.push(m_dTemp);
			stream.clear();
		}

		q.pop();
	}
	
	while (!operate.empty()) 
	{
		
		//遇到左括号
		if (operate.top() == ')') 
		{
			operate_temp.push(operate.top());
			operate.pop();
		}
		
		else
		{
		
			if (operate_temp.empty())
			{
				operate_temp.push(operate.top());
				figure_temp.push(figure.top());

				operate.pop();
				figure.pop();

				//operate可能为空
				if (operate.empty())
				{
					break;
				}

			}

			//运算符优先级比较计算 
			if ((operate_priority(operate.top()) < operate_priority(operate_temp.top())) && (operate_temp.top() != ')'))
			{
				//除数为0
				if (operate_temp.top() == '/'&&figure_temp.top() == 0) 
				{
					cout << "您输入的四则运算表达式出现除数为0的情况。请重新检查表达式的正确性！" << endl;
					exit(0);
				}

				_figure = calculate(operate_temp.top(), figure.top(), figure_temp.top());

				operate_temp.pop();
				figure.pop();
				figure_temp.pop();

				figure.push(_figure);
			}

			else
			{
				//遇到左括号
				if (operate.top() == ')')
				{
					operate_temp.push(operate.top());
					operate.pop();
				}
				//非左括号
				else 
				{
					operate_temp.push(operate.top());
					figure_temp.push(figure.top());

					operate.pop();
					figure.pop();
				}
			}

			//括号匹配
			if (!operate.empty() && !operate_temp.empty() && (operate.top() == '('&&operate_temp.top() == ')'))
			{
				operate.pop();
				operate_temp.pop();
			}

		}

	}
	
	while (!operate_temp.empty()) 
	{
		//除数为0
		if (operate_temp.top() == '/'&&figure_temp.top() == 0)
		{
			cout << "您输入的四则运算表达式出现除数为0的情况。请重新检查表达式的正确性！" << endl;
			exit(0);
		}

		_figure = calculate(operate_temp.top(), figure.top(), figure_temp.top());

		operate_temp.pop();
		figure.pop();
		figure_temp.pop();

		figure.push(_figure);
	}
	
	//输出最终计算结果
	printf("%.3f\n",figure.top());
	
}

//判断符号优先级
int operate_priority(char c)
{
	int pri;
	switch (c) 
	{
	case '+':
	case '-':
		pri = 0;
		break;
	case '*':
	case '/':
		pri = 1;
		break;
	case '(':
		pri = -1;
		break;
	case ')':
		pri = 2;
		break;
	}
	return pri;
}

//计算
double calculate(char oper, double front, double behind) 
{
	double result;
	switch(oper)
	{
	case '+':
		result = front + behind;
		break;
	case '-':
		result = front - behind;
		break;
	case '*':
		result = front * behind;
		break;
	case '/':
		result = front / behind;
		break;
	}
	return result;
}
