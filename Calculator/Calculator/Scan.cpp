
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
 HBING    2016/04/10      1.10         1.ʵ��-��ǰ��0�Ա�֤��ʽ�Ϸ���
                                       2.����Է��ŵ��жϣ��� + - * / ( ) �ſ������
 HBING    2016/04/13      1.11         ������λ������10λ���б���

********************************************************************************/

#include <string>
#include <queue>
#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string m_sInput) 
{

	string sInput;
	int nInputLength;
	
	for (int i = 0; i <= m_sInput.size(); i++) 
	{

		if (sInput.empty()) 
		{
			sInput = m_sInput[i];
			nInputLength = 1;
		}

		//����
		if (m_sInput[i] <= '9'&&m_sInput[i] >= '0' || m_sInput[i] == '.') 
		{

			//��λ����������
			if ((m_sInput[i + 1] <= '9'&&m_sInput[i + 1] >= '0') || m_sInput[i + 1] == '.') 
			{
				sInput += m_sInput[i + 1];
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

				q.push(sInput);
				sInput.clear();
			}

		}

		//����
		else if (m_sInput[i] == '+' || m_sInput[i] == '-' || m_sInput[i] == '*' || m_sInput[i] == '/' || m_sInput[i] == '(' || m_sInput[i] == ')')
		{
			//�Ƿ�����'-'ǰ��0
			if ((q.empty() || q.back() == "(") && m_sInput[i] == '-')
			{
				q.push("0");
			}
			
			q.push(sInput);
			sInput.clear();
		}
	}

}

