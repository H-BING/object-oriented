#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
using namespace std;
/***********************************************************************/
/***C++计算器项目的初始部分
 *  
 *  要求：
 *    <1>当输入的数字超过10位（包括小数位）时，报错。
 *    <2>能够处理不超过10位的任意实数
 *
 ***/
/***********************************************************************/

int main() {
	cout << "请输入四则运算表达式：" << endl;
	string input;
	cin >> input;
	
	Scan _scan;
	Print _print;
	_scan.ToStringQueue(input);
	_print.ToPrintQueue(_scan.q);
}