#include <iostream>
#include <unordered_set>

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
	int x = 0;
	unordered_set<int> us;
	while (n--)
	{
		int tmp;
		cin >> tmp;

		x ^= tmp;
		us.insert(tmp);
	}

	if (x == 0)
	{
		cout << "-1\n";
		return;
	}

	for (auto it : us)
	{
		if (us.find((it) ^ x) == us.end())
		{
			cout << "-1\n";
			return;
		}
	}

	cout << x << '\n';
}

main()
{
	FastIO;

	int ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}