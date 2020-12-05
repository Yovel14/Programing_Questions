#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n
	// x[i] is the effort the i th one made
	// devisable by 60 means devisable by 6*10 or 2^2*3*5
	// 5 - has 5 or zero
	// devisable by 4 - last two digits are devisable by 4
	// devisable by 3 - sum of digits devisable by 3

	// mast have: 0 ( not 0 and 5 becase if number ends with 5 it's not devisable by 4) and a number devisable by 2 and sum of digit devisable by 3
	// have 0, number devisable by 2, and sum of digits devisable by 3
	int t, digit, sum, count0;
	string n;
	bool dev2;
	cin >> t;
	while (t--)
	{
		cin >> n;

		sum = 0;
		count0 = 0;
		dev2 = false;
		for (char &c : n)
		{
			digit = c - '0';
			sum += digit;
			if (digit == 0)
				++count0;
			else if (!dev2 && digit % 2 == 0)
				dev2 = true;
		}
		if (sum % 3 == 0)
		{
			if ((dev2 && count0 > 0) || (count0 > 1))
				cout << "red" << '\n';
			else
				cout << "cyan" << '\n';
		}
		else
			cout << "cyan" << '\n';
	}

	return 0;
}