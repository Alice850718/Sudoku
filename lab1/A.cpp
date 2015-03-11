#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << "" << n;
	two:
	if( n%2 == 1 )
		n = 3*n +1;
	else
		n = n/2;
		cout << " " <<  n;
	if( n == 1)
	{
		cout << endl;
		return 0;
	}
	goto two;
}
