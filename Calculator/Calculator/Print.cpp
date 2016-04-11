
/********************************************************************************
FileName    :           Print.cpp

Author      :           HBING
Version     :           1.0
Date        :           2016/02/21

Description:
         ����Calculation���е��෽��

Function List:
         void ToPrintQueue        ����ַ�������
                                  �Բ�����Ҫ������ֽ��б���

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        ʵ������������ʽ�ļ���

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Print.h"
using namespace std;

void Print::ToPrintQueue(queue<string>q) 
{

	string m_str;//��ʱ�洢�ַ���

	while (!q.empty()) 
	{

		m_str = q.front();
		//�ж����ֳ���
		if (m_str.size() > 10) 
		{
			cout << "�����������λ������10λ������С��λ��" << endl;
			break;
		}
		cout << q.front() << endl;
		q.pop();

	}

}