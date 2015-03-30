#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Data
{
		public:
		float setData(float height, float mass);
		float getData();
		float count();
		string category();
		private:
		float a;
		float b;
		float BMI;
		string s;
};
