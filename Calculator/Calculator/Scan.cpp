#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string input) {

	/***
	 *cout << "Scan::ToStringQueue(string input)" << endl;
	 *���ϴ������ڼ����Ա�����Ƿ񱻵���
	 ***/


	 /*����m_strInput���飬����input[i]ת����string����*/
	string *m_strInput = new string[10000];
	if (m_strInput == NULL) {
		cout << "�ڴ�����ʧ�ܣ�" << endl;
	}
	for (int i = 0; i <= input.size(); i++) {
		m_strInput[i] = input[i];
	}


	/*��ȡ���������*/
	for (int i = 0; i <= input.size(); i++) {
		/***�ж�input[i]�Ƿ���input[i+1]��ͬ����һ��ʵ��***/
		/***
		 *��input[i]��input[i+1]��ͬ����һ��ʵ��
		 *��m_strInput[i]��m_strInput[i+1]�ϲ���һ���ַ���������m_strInput[i+1]��
		 *
		 *��֮����m_strInput[i]�������
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