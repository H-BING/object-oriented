
/********************************************************************************
FileName    :           Calculatoion.cpp

Author      :           HBING
Version     :           1.021
Date        :           2016/04/10

Description:
         ����Calculation���е��෽��

Function List:
         double ToCalculate          ʵ�ִ����ŵ�����������ʽ�ļ���
         int operate_priority        �жϷ������ȼ�
         double calculate            + - * / �򵥼���

History:

<author>    <time>     <version >            <desc>
 HBING    2016/04/10      1.0        ʵ������������ʽ�ļ���
 HBING    2016/04/13      1.01       �Ľ����Ŵ���
 HBING    2016/04/14      1.02       �����жϳ���Ϊ0�����
 HBING    2016/04/30      1.021      1.�޸ĺ�������λ��
                                     2.���stringstream����Ļ���

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
	double dTempFigure;//�ݴ��м������
	string sTempQueue;//�ݴ����Ԫ��
	stringstream stream;

	//���ַ��ŷֱ���stack
	while (!q.empty())
	{
		sTempQueue = q.front();

		//����
		if (sTempQueue[0] < '0' || sTempQueue[0] > '9')
		{
			stream << sTempQueue;
			stream >> m_cTemp;

			operate.push(m_cTemp);
			stream.clear();
			stream.str("");
		}

		//����
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

				//operate����Ϊ��
				if (operate.empty())
				{
					break;
				}

			}

			//��������ȼ��Ƚϼ��� 
			if ((operate_priority(operate.top()) < operate_priority(operate_temp.top())) && (operate_temp.top() != ')'))
			{
				//����Ϊ0
				if (operate_temp.top() == '/'&&figure_temp.top() == 0)
				{
					cout << "�����������������ʽ���ֳ���Ϊ0������������¼����ʽ����ȷ�ԣ�" << endl;
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
				//����������
				if (operate.top() == ')')
				{
					operate_temp.push(operate.top());
					operate.pop();
				}
				//��������
				else
				{
					operate_temp.push(operate.top());
					figure_temp.push(figure.top());

					operate.pop();
					figure.pop();
				}
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
		//����Ϊ0
		if (operate_temp.top() == '/'&&figure_temp.top() == 0)
		{
			cout << "�����������������ʽ���ֳ���Ϊ0������������¼����ʽ����ȷ�ԣ�" << endl;
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

//�жϷ������ȼ�
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

//����
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