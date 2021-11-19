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

int a[505][505];
int n;
int count1 = 0;

void dfs(int x, int y, int val)
{
	if (x >= n || y >= n || x < 0 || y < 0 || count1 == 0 || a[x][y] != -1)
		return;

	a[x][y] = val;
	count1--;
	dfs(x, y - 1, val);
	dfs(x + 1, y, val);
}

void inline solve()
{
	cin >> n;
	memset(a, -1, sizeof(a));
	for (int i = 0; i < n; i++)
		cin >> a[i][i];

	bool possible = true;
	for (int i = 0; i < n; i++)
	{
		count1 = a[i][i] - 1;
		dfs(i, i - 1, a[i][i]);
		dfs(i + 1, i, a[i][i]);

		if (count1 != 0)
		{
			possible = false;
			break;
		}
	}

	if (possible)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
	else
	{
		cout << -1 << '\n';
	}
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	cout << "\n\n";
	//cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}