#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void inline solve()
{
	int n, l, r, s;
	//n = 5, l = 2, r = 3, s = 5;
	cin >> n >> l >> r >> s;
	int k = r - l + 1;

	int lowSum = k * (k + 1) / 2;
	int highSum = k * (2 * n - k + 1) / 2;
	if (s < lowSum || s > highSum)
	{
		cout << -1 << '\n';
		return;
	}

	int used[n + 2];
	vector<int> ans(n, -1);
	memset(used, 0, sizeof(used));
	int val = n;
	for (int i = l - 1; i < r && s; i++)
	{
		while (val > 0 && s - val < (k - 1) * (k - 1 + 1) / 2)
			val--;

		if (val == 0)
		{
			cout << -1 << '\n';
			return;
		}

		ans[i] = val;
		s -= val;
		used[val] = true;
		k--;
		val--;
	}

	if (s != 0)
	{
		cout << -1 << '\n';
		return;
	}

	val = 1;
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == -1)
		{
			while (used[val])
				val++;
			ans[i] = val;
			val++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
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