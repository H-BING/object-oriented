
/********************************************************************************
FileName    :           Calculatoion.cpp

Author      :           HBING
Version     :           1.021
Date        :           2016/04/10

Description:
         定义Calculation类中的类方法

Function List:
         double ToCalculate          实现带括号的四则运算表达式的计算
         int operate_priority        判断符号优先级
         double calculate            + - * / 简单计算

History:

<author>    <time>     <version >            <desc>
 HBING    2016/04/10      1.0        实现四则运算表达式的计算
 HBING    2016/04/13      1.01       改进括号处理
 HBING    2016/04/14      1.02       补充判断除数为0的情况
 HBING    2016/04/30      1.021      1.修改函数声明位置
                                     2.清空stringstream对象的缓存

 ********************************************************************************/

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include "Calculation.h"
using namespace std;

double Calculation::ToCalculate(queue<string>q)
{
	double dTempFigure;//暂存中间计算结果
	string sTempQueue;//暂存队列元素
	stringstream stream;

	//数字符号分别入stack
	while (!q.empty())
	{
		sTempQueue = q.front();

		//符号
		if (sTempQueue[0] < '0' || sTempQueue[0] > '9')
		{
			stream << sTempQueue;
			stream >> m_cTemp;

			operate.push(m_cTemp);
			stream.clear();
			stream.str("");
		}

		//数字
		else
		{
			stream << sTempQueue;
			stream >> m_dTemp;

			figure.push(m_dTemp);
			stream.clear();
			stream.str("");
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

				dTempFigure = calculate(operate_temp.top(), figure.top(), figure_temp.top());

				operate_temp.pop();
				figure.pop();
				figure_temp.pop();

				figure.push(dTempFigure);
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

		dTempFigure = calculate(operate_temp.top(), figure.top(), figure_temp.top());

		operate_temp.pop();
		figure.pop();
		figure_temp.pop();

		figure.push(dTempFigure);
	}
	
	m_dResult = figure.top();
	figure.pop();

	return m_dResult;
}

//判断符号优先级
int Calculation::operate_priority(char c)
{
	int nPri;
	switch (c)
	{
	case '+':
	case '-':
		nPri = 0;
		break;
	case '*':
	case '/':
		nPri = 1;
		break;
	case '(':
		nPri = -1;
		break;
	case ')':
		nPri = 2;
		break;
	}
	return nPri;
}

//计算
double Calculation::calculate(char dOper, double dFront, double dBehind)
{
	double dResult;
	switch (dOper)
	{
	case '+':
		dResult = dFront + dBehind;
		break;
	case '-':
		dResult = dFront - dBehind;
		break;
	case '*':
		dResult = dFront * dBehind;
		break;
	case '/':
		dResult = dFront / dBehind;
		break;
	}
	return dResult;
}