#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void inline solve()
{
	int n;
	cin >> n;
	int m = n + 2;
	vector<int> v(m);
	unordered_map<ll, int> um; // value, index

	ll sum = 0; // 2*sum + x     // sum is the sum of a[1]+...a[n]
				// so find (TSum-x)/2 TSum is even and if it's exist and not is not in the index of x than it's the answer

	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
		sum += v[i];
		um[v[i]] = i;
	}

	bool found = false;
	int i, j;
	for (i = 0; i < m; i++)
	{
		ll tmp = sum - v[i];
		if (tmp & 1 ^ 1)
		{
			unordered_map<ll, int>::iterator it = um.find(tmp / 2);
			if (it != um.end())
			{
				if (it->second != i)
				{
					j = it->second;
					found = true;
					break;
				}
				um.erase(it);
			}
		}
	}

	if (!found)
		cout << -1 << '\n';
	else
	{
		for (int k = 0; k < m; k++)
			if (i != k && j != k)
				cout << v[k] << ' ';
		cout << '\n';
	}
}

main()
{
	FastIO;

	int ctc = 1;
	cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}