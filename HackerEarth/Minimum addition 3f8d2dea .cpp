#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
#define vi vector<int>

using ll = long long;
using namespace std;

const int MOD = 1000000007;

main()
{
	FastIO;

	int n;
	cin >> n;

	ll dp[n + 1][32];

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		for (int mask = 0; mask < 31; mask++)
			dp[i + 1][mask] = dp[i][mask] + max(0, (1 << mask) - (num & (1 << (mask + 1)) - 1));
	}

	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		ll ans = LLONG_MAX;
		for (int mask = 0; mask < 31; mask++)
			ans = min(ans, dp[r][mask] - dp[l - 1][mask]);
		cout << ans << '\n';
	}
}