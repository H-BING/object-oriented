
/********************************************************************************
FileName    :           Scan.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/04/10

Description:
         ����Scan���е��෽��

Function List:
         void ToStringQueue        �������������ʽ

History:

<author>    <time>     <version>            <desc>
 HBING    2016/02/21      1.0          �������������ʽ
 HBING    2016/04/10      1.10         ʵ��-��ǰ��0�Ա�֤��ʽ�Ϸ���
                                       ����Է��ŵ��жϣ��� + - * / ( ) �ſ������
 HBING    2016/04/13      1.11         ������λ������10λ���б���

********************************************************************************/

#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string input) 
{

	string m_strInput;
	int nInputLength;
	
	for (int i = 0; i <= input.size(); i++) 
	{

		if (m_strInput.empty()) 
		{
			m_strInput = input[i];
			nInputLength = 1;
		}

		//����
		if (input[i] <= '9'&&input[i] >= '0' || input[i] == '.') 
		{

			//��λ����������
			if ((input[i + 1] <= '9'&&input[i + 1] >= '0') || input[i + 1] == '.') 
			{
				m_strInput += input[i + 1];
				nInputLength++;
			}

			//һλ����
			else 
			{
				//����λ������10λ����
				if (nInputLength > 10) 
				{
					cout << "�����������λ������10λ������С��λ��" << endl;
					exit(0);
				}

				q.push(m_strInput);
				m_strInput.clear();
			}

		}

		//����
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')
		{
			//�Ƿ�����'-'ǰ��0
			if ((q.empty() || q.back() == "(") && input[i] == '-')
			{
				q.push("0");
			}
			
			q.push(m_strInput);
			m_strInput.clear();
		}
	}

}

