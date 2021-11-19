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

// Special types
template <typename T>
using vc = std::vector<T>;
template <class T>
using vc = std::vector<T>;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using ll = long long;

using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

void inline solve()
{
	int n, m;
	n = 2, m = 3;
	cin >> n >> m;

	pair<int, pair<int, int>> all[n * m];
	int mat[n][m];
	int p = 0;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
		{
			cin >> all[p].first;
			all[p].second.first = r;
			all[p].second.second = c;
			mat[r][c] = all[p].first;
			p++;
		}

	sort(all, all + n * m);

	int ans[n][m];
	memset(ans, -1, sizeof(ans));

	for (int i = 0, k = 0; k < m; i++, k++)
	{
		ans[all[i].second.first][k] = all[i].first;
		mat[all[i].second.first][all[i].second.second] = -1;
	}

	for (int r = 0; r < n; r++)
	{
		int c1 = 0;
		int c2 = 0;
		while (c1 < m && c2 < m)
		{
			if (ans[r][c1] != -1)
				c1++;
			else if (mat[r][c2] == -1)
				c2++;
			else
				ans[r][c1++] = mat[r][c2++];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
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