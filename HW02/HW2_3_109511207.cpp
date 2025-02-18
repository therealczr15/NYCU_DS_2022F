#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double squareRoot(int,double,double);

int main()
{
	int times;
	int num;
	cin >> times;
	for(int i=0;i<times;i++)
	{
		cin >> num;
		cout << fixed << setprecision(2) << squareRoot(num,1,0.01) << '\n';
	}
	return 0;
}

double squareRoot(int num, double ans, double tol)
{
	if(fabs(ans*ans-num)<= tol)
		return ans;
	else
		return squareRoot(num,(ans*ans+num)/(2*ans),tol);
}
