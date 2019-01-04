// Algorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void OutPrintVector(vector<int> &arry)
{
	for (int i = 0; i < arry.size(); i++)
	{
		cout <<"   " <<arry[i];
	}
	cout << endl;
}
//ָ����������� ����
void ReverseVectorSection(vector<int>& arry, int s1, int e1)
{
	if (arry.empty() || e1 <=s1 || s1<0 || e1<0)
		return;
	int nCount = e1-s1+1;
	for (int i = 0; i < nCount / 2; i++)
	{
		int temp = arry[s1+i];
		arry[s1+i] = arry[e1 - i];
		arry[e1 - i] = temp;
	}
}
//ʵ��˼·���� s1��e2 ����3������� s1->e1 e1+1-->s2-1(�������������)  s2 -->e2   �ֱ������� ������s1-->e2 ���ü���
void swap_range(vector<int>& arry, int s1, int e1, int s2, int e2)
{
	if (e1 >= s2)  //�������ཻ���������
		return;
	ReverseVectorSection(arry,s1, e1);
	ReverseVectorSection(arry, s2, e2);
	 //�������
	if (e1 + 1 != s2)
	{
		ReverseVectorSection(arry, e1 + 1, s2 - 1);
	}
	OutPrintVector(arry);
	ReverseVectorSection(arry, s1, e2);
	OutPrintVector(arry);
}
int main()
{
	vector<int> arry = { 1,2,3,4,8,1,5,7,6,9 }/*{0,1,2,3,4,5,6,7,8,9}*/;
	OutPrintVector(arry);
	cout << endl;
	swap_range(arry, 2, 3, 4, 5);
	system("PAUSE ");
    return 0;
}

