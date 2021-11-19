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

using ll = long long;
using namespace std;

const int MOD = 1000000007;
const int N = 10;
const int M = 200009;
ll dp[N][M];

ll dfs(int n, int m)
{
	if (m == 0)
		return dp[n][m] = 1;

	if (dp[n][m] != -1)
		return dp[n][m];
	if (n < 9)
		return dp[n][m] = dfs(n + 1, m - 1) % MOD;
	else
		return dp[n][m] = (dfs(1, m - 1) % MOD + dfs(0, m - 1) % MOD) % MOD;
}

void inline preCampute()
{
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dfs(i, j);
}

void inline solve()
{
	string str;
	int m;
	cin >> str >> m;
	ll ans = 0;
	for (int i = 0; i < str.size(); i++)
		ans = (ans + dp[str[i] - '0'][m]) % MOD;
	cout << ans << '\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}
// Solution 2:
// optimized space
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

using ll = long long;
using namespace std;

const int MOD = 1000000007;
const int M = 200009;
ll dp[M];

void inline preCampute()
{
	for (int i = 0; i < 9; i++)
		dp[i] = 2;
	dp[9] = 3;
	for (int i = 10; i < M; i++)
		dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
}

void inline solve()
{
	string str;
	int m;
	cin >> str >> m;
	ll ans = 0;
	for (int i = 0; i < str.size(); i++)
		ans = (ans + (str[i] - '0' + m < 10 ? 1 : dp[m + str[i] - '0' - 10])) % MOD;
	cout << ans << '\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}