#include <iostream>
#include <vector>

using namespace std;

int Min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;

	return c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// r , g ,b , w
	// take red green blue and change color to white

	// what amounts can be rearenged to a palindrome?
	// if sum is odd than only one of the r,g,b,w can be odd
	// if sum is even than all ball counts sould be even

	int t, r, g, b, w, count, sum;
	cin >> t;
	while (t--)
	{
		cin >> r >> g >> b >> w;

		sum = r + g + b + w;
		count = r % 2 + g % 2 + b % 2 + w % 2; // how many are odd
		if (sum % 2 == 0)
		{
			if (count == 0 || (count == 4 && Min(r, g, b) != 0))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		else // sum is odd
		{
			if (count == 1 || (count == 3 && Min(r, g, b) != 0))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}