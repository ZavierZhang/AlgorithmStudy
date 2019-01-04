// Algorithm.cpp : 定义控制台应用程序的入口点。
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
//指定数据区域段 逆置
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
//实现思路，将 s1到e2 看出3个区域段 s1->e1 e1+1-->s2-1(这里有相邻情况)  s2 -->e2   分别将其逆置 再整体s1-->e2 逆置即可
void swap_range(vector<int>& arry, int s1, int e1, int s2, int e2)
{
	if (e1 >= s2)  //不考虑相交包含的情况
		return;
	ReverseVectorSection(arry,s1, e1);
	ReverseVectorSection(arry, s2, e2);
	 //相邻情况
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

