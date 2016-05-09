#pragma once
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Print 
{

public:

	//输出拆分队列
	void ToPrintQueue(queue<string>q);

	//以文件方式输出结果
	void ToPrintIs_f(string sText_txt, string sResult_txt);

	//以非文件方式输出结果
	void ToPrintIsNot_f(string sInput, bool bIs_a);
	
private:
	
};

