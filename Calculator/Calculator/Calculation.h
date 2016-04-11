#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

class Calculation 
{

public:

	//计算表达式的值
	void ToCalculate(queue<string>q);



private:

	double m_dTemp;
	char m_cTemp;

	//存储数字
	stack<double>figure;
	stack<double>figure_temp;

	//存储符号
	stack<char>operate;
	stack<char>operate_temp;

};