#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include"lab3_A_headfile.h"
using namespace std;

int main()
{
		int n, i, sum = 0;
		//開檔
		ifstream fin("file.in",ios::in);
		ofstream fout("stdout",ios::out);
		//當檔案開啟失敗則結束程式
		if(!fin)
		{
				cerr << "Failed opening" << endl;
				exit(1);
		}
		if(!fout)
		{
				cerr << "Failed opening" << endl;
				exit(1);
		}
		//讀取檔案
		//讀入牛隻數(n)
		fin >> n;
//		vector<int> cow_weight(8);
		int cow_weight[8];
		for(i = 0; i < n; i ++)
		{
				fin >> cow_weight[ i ]; 
		}
		//使用物件
		Lab3_A a;
		a.Count(cow_weight, n, sum);
		cout << a.Count(cow_weight, n, sum) << endl;
		fin.close();
		fout.close();
}
