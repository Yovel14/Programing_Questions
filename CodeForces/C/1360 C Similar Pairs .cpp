#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, even, odd;
	int temp;
	cin >> t;
	bool has_pair;
	while (t--)
	{
		cin >> n;
		even = 0;
		odd = 0;
		has_pair = false;
		vector<int> v(n);
		for (int &it : v)
		{
			cin >> it;
			if (it % 2 == 0)
				++even;
			else
				++odd;
		}

		if ((even & 1) != (odd & 1))
			cout << "NO" << '\n';
		else
		{
			if (even % 2 == 0)
				cout << "YES\n";
			else
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = i + 1; j < n; ++j)
					{
						if (v[i] % 2 != v[j] % 2 && (v[i] + 1 == v[j] || v[j] + 1 == v[i]))
						{
							has_pair = true;
							break;
						}
					}
					if (has_pair)
						break;
				}
				if (has_pair)
					cout << "YES" << '\n';
				else
					cout << "NO" << '\n';
			}
		}
	}

	return 0;
}