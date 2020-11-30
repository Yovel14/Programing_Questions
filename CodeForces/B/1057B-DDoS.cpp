#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ddos is req > 100 * t
	int n;
	cin >> n;
	vector<int> r(n);
	for (int &it : r)
		cin >> it;
	int mx = 0;
	int sum;

	for (int i = 0; i < n; ++i)
	{
		sum = r[i];
		if (sum > 100)
			mx = max(mx, 1);
		for (int j = i + 1; j < n; ++j)
		{
			sum += r[j];

			int temp = 100 * (j - i + 1);

			if (sum > 100 * (j - i + 1))
				if (j - i + 1 > mx)
					mx = j - i + 1;
		}
	}

	cout << mx;

	return 0;
}