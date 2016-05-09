
/********************************************************************************
FileName    :           Print.cpp

Author      :           HBING
Version     :           1.0
Date        :           2016/02/21

Description:
         ����Calculation���е��෽��

Function List:
         void ToPrintQueue        1.����ַ�������
                                  2.�Բ�����Ҫ������ֽ��б���
		 void ToPrintIsNot_f      �Է��ļ���ʽ������
		 void ToPrintIs_f         ���ļ���ʽ������

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        ʵ�ֶ�����������ʽ�Ĳ�ֽ�������
 HBING    2016/05/08      1.1        ����ͬ�������Ҫ������Ӧ��ʽ������ս��

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <fstream>

#include "Scan.h"
#include "Print.h"
#include "Calculation.h"

using namespace std;

//�Է��ļ���ʽ������
void Print::ToPrintIsNot_f(string sInput, bool bIs_a)
{
	Scan scan;
	Calculation calculate;

	//��ֱ��ʽ
	scan.ToStringQueue(sInput);

	//������ʽ��ֵ
	calculate.ToCalculate(scan.q);

	if (bIs_a)
	{
		cout << sInput << "= ";
	}
	cout << calculate.m_dResult << endl;
}

//���ļ���ʽ������
void Print::ToPrintIs_f(string sText_txt, string sResult_txt) 
{
	
	ifstream in;
	ofstream out;

	//���ļ�
	in.open(sText_txt.c_str(), ios::in);
	out.open(sResult_txt.c_str(), ios::out);
	
	while (!in.eof())
	{
		Scan scan;
		Calculation calculate;
		string sExperssion;
		
		//��sText_txt·����ȡ����
		getline(in, sExperssion, '\n');

		//��ֱ��ʽ
		scan.ToStringQueue(sExperssion);

		
		//������ʽ��ֵ
		calculate.ToCalculate(scan.q);

		//��sResult_txt·����������
		out << calculate.m_dResult << endl;
	}

	//�ر��ļ�
	in.close();
	out.close();
}

void Print::ToPrintQueue(queue<string>q) 
{

	string m_sStr;//��ʱ�洢�ַ���

	while (!q.empty()) 
	{
		m_sStr = q.front();

		//�ж����ֳ���
		if (m_sStr.size() > 10) 
		{
			cout << "�����������λ������10λ������С��λ��" << endl;
			break;
		}
		cout << q.front() << endl;

		q.pop();
	}

}