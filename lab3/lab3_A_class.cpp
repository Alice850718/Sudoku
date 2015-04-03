#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "lab3_A_headfile.h"
using namespace std;

int Lab3_A::Count(int cow_weight[], int n, int sum)
{
		int i;
		sum = 0;
		//依照升冪排列
		sort(cow_weight,cow_weight + n);
		//用for迴圈計算前五重的總和
		for( i = n-5; i < n; i ++)
		{
				sum = sum + cow_weight[ i ];
		}
		return sum;
}
