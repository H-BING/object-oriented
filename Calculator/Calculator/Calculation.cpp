
/********************************************************************************
FileName    :           Calculatoion.cpp

Author      :           HBING
Version     :           1.0
Date        :           2016/04/10

Description:
         ����Calculation���е��෽��

Function List:
         void ToCalculate          ʵ�ִ����ŵ�����������ʽ�ļ���
         int operate_priority      �жϷ������ȼ�
         double calculate          + - * / �򵥼���

History:

<author>    <time>     <version >            <desc>
 HBING    2016/04/10      1.0        ʵ������������ʽ�ļ���

 ********************************************************************************/

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include "Calculation.h"
using namespace std;

void Calculation::ToCalculate(queue<string>q)
{
	int operate_priority(char c);
	double calculate(char oper, double front, double behind);

	double _figure;
	stringstream stream;
	string m_strQue;

	//���ַ��ŷֱ���stack
	while (!q.empty()) 
	{
		m_strQue = q.front();

		if (m_strQue[0] < '0' || m_strQue[0] > '9')
		{
			stream << m_strQue;
			stream >> m_cTemp;

			operate.push(m_cTemp);
			stream.clear();
		}
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
		
		//����������
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

				//operateΪ��
				if (operate.empty())
				{
					break;
				}

			}

			//��������ȼ��Ƚϼ��� 
			if ((operate_priority(operate.top()) < operate_priority(operate_temp.top())) && (operate_temp.top() != ')'))
			{
				_figure = calculate(operate_temp.top(), figure.top(), figure_temp.top());

				operate_temp.pop();
				figure.pop();
				figure_temp.pop();

				figure.push(_figure);
			}

			else
			{
				operate_temp.push(operate.top());
				figure_temp.push(figure.top());

				operate.pop();
				figure.pop();
			}

			//����ƥ��
			if (!operate.empty() && !operate_temp.empty() && (operate.top() == '('&&operate_temp.top() == ')'))
			{
				operate.pop();
				operate_temp.pop();
			}

		}

	}
	
	while (!operate_temp.empty()) 
	{
		_figure = calculate(operate_temp.top(), figure.top(), figure_temp.top());

		operate_temp.pop();
		figure.pop();
		figure_temp.pop();

		figure.push(_figure);
	}
	
	cout << figure.top() << endl;
}

//�жϷ������ȼ�
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

//����
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
