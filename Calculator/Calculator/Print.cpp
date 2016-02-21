#include <iostream>
#include <string>
#include <queue>
#include "Print.h"
using namespace std;

void Print::ToPrintQueue(queue<string>q) {

	/*
	 *cout << "Print::ToPrintQueue(queue<string>q)" << endl;
	 *以上代码用于检验成员函数是否被调用
	 */
	
	while (!q.empty()) {
		str = q.front();
		if (str.size() > 10) {
			cout << "您输入的数字数字超过10位（包括小数位）" << endl;
			break;
		}
		cout << q.front() << endl;
		q.pop();
	}
}