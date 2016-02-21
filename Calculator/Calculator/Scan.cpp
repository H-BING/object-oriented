#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string input) {

	/***
	 *cout << "Scan::ToStringQueue(string input)" << endl;
	 *以上代码用于检验成员函数是否被调用
	 ***/


	 /*定义m_strInput数组，并将input[i]转换成string类型*/
	string *m_strInput = new string[10000];
	if (m_strInput == NULL) {
		cout << "内存申请失败！" << endl;
	}
	for (int i = 0; i <= input.size(); i++) {
		m_strInput[i] = input[i];
	}


	/*提取数字与符号*/
	for (int i = 0; i <= input.size(); i++) {
		/***判断input[i]是否与input[i+1]共同构成一个实数***/
		/***
		 *若input[i]与input[i+1]共同构成一个实数
		 *将m_strInput[i]与m_strInput[i+1]合并成一个字符串并赋到m_strInput[i+1]上
		 *
		 *反之，则将m_strInput[i]存入队列
		 ***/
		if (input[i] <= '9'&&input[i] >= '0' || input[i] == '.') {
			if ((input[i + 1] <= '9'&&input[i + 1] >= '0') || input[i + 1] == '.') {
				m_strInput[i] += m_strInput[i + 1];
				m_strInput[i + 1] = m_strInput[i];
			}
			else {
				q.push(m_strInput[i]);
			}
		}
		else {
			q.push(m_strInput[i]);
		}
	}

	delete[]m_strInput;
	m_strInput = NULL;
}