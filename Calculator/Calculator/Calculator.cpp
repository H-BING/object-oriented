
/********************************************************************************
FileName    :           Calculator.cpp

Author      :           HBING
Version     :           1.1
Date        :           2016/02/21

Description:
         ��������ŵ�����������ʽ��
             1��ֱ�����������ֵ
             2������"-a"ʱд���������ʽ
			 3������"-f"ʱ���ļ���ȡ���ݲ����ļ���������ս��

Function List:
         int main()                               �������
		 void ToDrawOperationInterface()          ���Ʋ���ָ��

History:

<author>    <time>     <version >            <desc>
 HBING    2016/02/21      1.0        ʵ������������ʽ�Ĳ�ж
 HBING    2016/04/10      1.1        ʵ������������ʽ�ļ���
 HBING    2016/05/08      1.2        �������뷽ʽ��������ͬҪ��������

 ********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Print.h"
using namespace std;

//���Ʋ���ָ��
void ToDrawOperationInterface()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	cout << "    һ. ע�����" << endl;
	cout << "        1. ������Ϸ�����������ʽ" << endl;
	cout << "        2. ���������λ��������10λ������С��λ��" << endl;
	cout << "        3. ����������С�������λ" << endl;
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	cout << "    ��. ���������ʽ��" << endl;
	cout << "        ��X�����һ����������Y����ڶ�����������Z�������������" << endl;
	cout << "        1. XΪ���ʽ��Y��ZΪ�ա�ֻ�����������" << endl;
	cout << "        2. XΪ��-a����YΪ���ʽ��ZΪ�ա�����������ʽ��" << endl;
	cout << "        3. XΪ��-f����Y��ZΪtxt�ļ���·����" << endl;
	cout << "           ��Y·���ж�ȡ���ʽ�����������Z·���ϡ�" << endl;
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
}

//������
int main(int argc, char* argv[])
{
	//���Ʋ���ָ��
	ToDrawOperationInterface();

	string sInput;
	bool bIs_a = false;//����Ƿ�����-a

	Print print;
	string text_txt, result_txt;

	int i;
	for (i = 1; i < argc; i++) 
	{
		sInput = argv[i];

		//���Ϊ-a��ʽ���
		if (sInput == "-a") 
		{
			bIs_a = !bIs_a;
		}
		//���ļ����
		else if (sInput == "-f") 
		{
			text_txt = argv[++i];
			result_txt = argv[++i];

			print.ToPrintIs_f(text_txt, result_txt);
		}
		//�Է��ļ����
		else 
		{
			print.ToPrintIsNot_f(sInput, bIs_a);
		}
		
		sInput.clear();
	}
	
	return 0;
}