
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
 HBING    2016/04/10      1.1          ʵ��-��ǰ��0�Ա�֤��ʽ�Ϸ���
                                       ����Է��ŵ��жϣ��� + - * / ( ) �ſ������

********************************************************************************/

#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string input) 
{

	string m_strInput;
	
	for (int i = 0; i <= input.size(); i++) 
	{
		
		if (m_strInput.empty()) 
		{
			m_strInput = input[i];
		}

		//����
		if (input[i] <= '9'&&input[i] >= '0' || input[i] == '.') 
		{

			//��λ����������
			if ((input[i + 1] <= '9'&&input[i + 1] >= '0') || input[i + 1] == '.') 
			{
				m_strInput += input[i + 1];
			}

			//һλ����
			else 
			{
				q.push(m_strInput);
				m_strInput.clear();
			}

		}
		//����
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')
		{
			if ((q.empty() || q.back() == "(") && input[i] == '-')
			{
				q.push("0");
			}
			
			q.push(m_strInput);
			m_strInput.clear();
		}
	}

}

