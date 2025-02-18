#include <iostream>
#include <iomanip>

using namespace std;

long long combination(int ,int);

int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		if((n == -1) || (k == -1))
			break;
		cout << combination(n,k) << '\n';
	}
	return 0;
}

long long combination(int n, int k)
{
	if((k == 0) || (n == k))
		return 1;
	else if((n > k) && (k > 0))
		return combination(n-1,k) + combination(n-1,k-1);
}
