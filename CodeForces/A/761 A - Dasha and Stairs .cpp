#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// if  the abs(a-b) >1 than it is impossible for consecitive stepps because even and odd numbers are alterating
	int a, b;
	cin >> a >> b;
	if (a - b > 1 || b - a > 1 || (a == 0 && b == 0)) // a = 0 and b = 0 is base case because l,r are at least 1 thus  a and b can't be 0
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';

	return 0;
}