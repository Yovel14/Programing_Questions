#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstddef>
#include <unordered_set>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
using namespace std;

// Time : O(n^2 + m^2)
void solve()
{
	string a, b;
	cin >> a >> b;
	unordered_set<string> us;
	int n = a.size();
	string tmp = "";

	for (int i = 0; i < n; i++)
	{
		tmp.clear();
		for (int j = i; j < n; j++)
		{
			tmp.push_back(a[j]);
			us.insert(tmp);
		}
	}

	int mx_length = 0;
	int m = b.size();
	for (int i = 0; i < m; i++)
	{
		tmp.clear();
		for (int j = i; j < m; j++)
		{
			tmp.push_back(b[j]);
			if (us.find(tmp) != us.end())
				mx_length = max(mx_length, int(tmp.size()));
		}
	}

	cout << (n - mx_length + m - mx_length) << '\n';
}

main()
{
	FastIO;

	int ctc;
	ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}