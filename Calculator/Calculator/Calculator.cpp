
/********************************************************************************
FileName    :           Calculator.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/02/21

Description:
         ��������ŵ�����������ʽ��
             1��ֱ�����������ֵ
             2������"-a"ʱд���������ʽ

Function List:
         int main()      �������

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        ʵ������������ʽ�Ĳ�ж
 HBING    2016/04/10      1.1        ʵ������������ʽ�ļ���

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;


int main(int argc, char* argv[])
{
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
	cout << "    ע�����" << endl;
	cout << "        1��������Ϸ�����������ʽ" << endl;
	cout << "        2�����������λ��������10λ������С��λ��" << endl;
	cout << "        3������������С�������λ" << endl;
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl << "����������������ʽ��" << endl << endl;

	string sInput;
	int nTemp = 0;//����Ƿ�����"-a"
	
	int i;
	for (i = 1; i < argc; i++) 
	{

		sInput = argv[i];

		Scan scan;
		//Print print;
		Calculation calculate;

		if(sInput=="-a")
		{
			nTemp = 1;
			continue;
		}

		//�ж��Ƿ�������-a
		if (nTemp == 1) 
		{
			cout << sInput << "= ";
		}
		else 
		{
			cout << "������Ϊ��";
		}

		//��ֱ��ʽ
		scan.ToStringQueue(sInput);

		/*
		//���ò������ֺõĶ���
		print.ToPrintQueue(scan.q);
		*/

		//������ʽ��ֵ
		calculate.ToCalculate(scan.q);

		sInput.clear();
	}
	

	return 0;
}