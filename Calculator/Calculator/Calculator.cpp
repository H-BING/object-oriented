
/********************************************************************************
FileName    :           Calculator.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/02/21

Description:
         ��������ŵ�����������ʽ��
             1��ֱ�����������ֵ
             2������-aʱд���������ʽ

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
	
	string input;
	int temp = 0;
	
	int i;
	for (i = 1; i < argc; i++) {
		
		input = argv[i];

		Scan scan;
		Print print;
		Calculation calculate;

		if(input=="-a")
		{
			temp = 1;
			continue;
		}

		if (temp == 1) {
			cout << input << "= ";
		}

		//��ֱ��ʽ
		scan.ToStringQueue(input);

		/*
		//���ò������ֺõĶ���
		print.ToPrintQueue(scan.q);
		*/

		//������ʽ��ֵ
		calculate.ToCalculate(scan.q);

		input.clear();
	}
	
	return 0;
}