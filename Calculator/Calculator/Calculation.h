#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

class Calculation 
{

public:

	//�������ʽ��ֵ
	void ToCalculate(queue<string>q);



private:

	double m_dTemp;
	char m_cTemp;

	//�洢����
	stack<double>figure;
	stack<double>figure_temp;

	//�洢����
	stack<char>operate;
	stack<char>operate_temp;

};