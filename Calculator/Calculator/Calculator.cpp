#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
using namespace std;
/***********************************************************************/
/***C++��������Ŀ�ĳ�ʼ����
 *  
 *  Ҫ��
 *    <1>����������ֳ���10λ������С��λ��ʱ������
 *    <2>�ܹ���������10λ������ʵ��
 *
 ***/
/***********************************************************************/

int main() {
	cout << "����������������ʽ��" << endl;
	string input;
	cin >> input;
	
	Scan _scan;
	Print _print;
	_scan.ToStringQueue(input);
	_print.ToPrintQueue(_scan.q);
}