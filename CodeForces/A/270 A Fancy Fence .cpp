#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//(n-2)*180/n = a
	//180n-360 = an
	//180n -an = 360
	//(180-a)*n = 360
	// n = 360/(180 - a)
	// n has to be a whole positive number thus if not it is not possible

	int t;
	double temp, a;
	cin >> t;
	while (t--)
	{
		cin >> a;
		temp = 360 / (180 - a);
		cout << (temp == (int(temp)) ? "YES" : "NO") << '\n';
	}

	return 0;
}