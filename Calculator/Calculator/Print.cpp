#include <iostream>
#include <string>
#include <queue>
#include "Print.h"
using namespace std;

void Print::ToPrintQueue(queue<string>q) {

	/*
	 *cout << "Print::ToPrintQueue(queue<string>q)" << endl;
	 *���ϴ������ڼ����Ա�����Ƿ񱻵���
	 */
	
	while (!q.empty()) {
		str = q.front();
		if (str.size() > 10) {
			cout << "��������������ֳ���10λ������С��λ��" << endl;
			break;
		}
		cout << q.front() << endl;
		q.pop();
	}
}