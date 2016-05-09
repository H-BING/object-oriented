#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

class Calculation
{

public:

	//������ʽ��ֵ
	double ToCalculate(queue<string>q);

	//�洢������
	double m_dResult;

private:

	double m_dTemp;
	char m_cTemp;

	//�洢����
	stack<double>figure;
	stack<double>figure_temp;

	//�洢����
	stack<char>operate;
	stack<char>operate_temp;

	//�жϷ������ȼ�
	int operate_priority(char c);

	// + - * / ����
	double calculate(char dOper, double dFront, double dBehind);

};