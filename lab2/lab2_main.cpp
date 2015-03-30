#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lab2_headfile.h"
using namespace std;
int main()
{
		Data data;
		string s;
		float height, mass, BMI, a, b;
		ifstream inf("file.in",ios::in);
		ofstream outf("file.out",ios::out);
		if(!outf)
		{
				cerr << "Failed opening" << endl;
				exit(1);
		}
		if(!inf)
		{
				cerr << "Failed opening" << endl;
				exit(1);
		}
		while( height != 0 && mass != 0)
		{
				inf >> height >> mass;
				if( height == 0)
				{
						break;
				}
				data.setData(height, mass);
				data.getData();
//				data.category(s, BMI);
				outf << data.count() << "\t" << data.category() << endl;
		}
		inf.close();
		outf.close();
}
