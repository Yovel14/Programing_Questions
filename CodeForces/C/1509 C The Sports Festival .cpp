#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>
#include <stack>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
using ll = long long;
using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

vector<ll> a;
vector<vector<ll>> dp;

ll dfs(int l, int r)
{
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l == r)
		return 0;
	return dp[l][r] = a[r] - a[l] + min(dfs(l + 1, r), dfs(l, r - 1));
}

void inline solve()
{
	int n;
	cin >> n;
	a = vector<ll>(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	dp = vector<vector<ll>>(n, vector<ll>(n, -1));
	cout << dfs(0, n - 1);
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	//cout << "\n\n";
	//cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}