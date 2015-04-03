#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Lab3_A
{
		public:
		int Count(int cow_weight[], int n, int sum);
		private:
		static int n;
		int sum;
		vector<int> cow_weight(int n);
};
