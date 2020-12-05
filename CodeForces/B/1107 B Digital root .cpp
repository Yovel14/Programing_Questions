#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int t, k, x;
	cin >> t;
	while (t--)
	{
		cin >> k >> x;
		// base formula for digital root is   (x-1) mod 9 +1
		// if we add 9 to some number it will have the same digital root thus the k th digital root is (k-1)*9 + x
		cout << (k - 1) * 9 + x << '\n';
	}

	return 0;
}