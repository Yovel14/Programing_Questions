#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n different shops
	// price of drink in i th shop is x[i]
	// but for q consecutive days
	// on i th day spend m[i] money

	int n, q, m, low, high;

	n = 5;
	cin >> n;
	vector<int>
		x(n);

	for (int &it : x)
		cin >> it;

	sort(x.begin(), x.end());

	cin >> q;
	while (q--)
	{
		cin >> m;
		int low = 0, high = n - 1, mid;
		if (n == 0 || (n > 0 && m < x[0]))
		{
			cout << 0 << '\n';
		}
		else
		{
			while (low < high)
			{
				mid = low + (high - low) / 2 + 1;
				if (x[mid] > m)
					high = mid - 1;
				else
					low = mid;
			}
			cout << high + 1 << '\n';
		}
	}

	return 0;
}