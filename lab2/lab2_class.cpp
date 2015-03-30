#include <iostream>
#include <fstream>
#include "lab2_headfile.h"
using namespace std;
float Data::setData(float height, float mass)
{
		a = height;
		b = mass;
}
float Data::getData()
{
		return a,b,BMI;
}
float Data::count()
{		
		BMI = b/a/a*10000;
		cout << BMI << endl;
		return BMI;
}
string Data::category()
{
		BMI = b/a/a*10000;
		if( BMI < 15 )
		{
				s = "Very severely underweight";
		}
		if( BMI >= 15 && BMI < 16)
		{
				s = "Severely underweight";
		}
		if( BMI >= 16 && BMI < 18.5)
		{
				s = "Underweight";
		}
		if( BMI >= 18.5 && BMI < 25)
		{
				s = "Normal";
		}
		if( BMI >= 25 && BMI < 30)
		{
				s = "Overweight";
		}
		if( BMI >= 30 && BMI < 35)
		{
				s = "Obese Class I (Moderately obese)";
		}
		if( BMI >= 35 && BMI < 40)
		{
				s = "Obese Class II (Severely obese)";
		}
		if( BMI >= 40)
		{
				s = "Obese Class III (Very severely obese)";
		}
		return s;
}
