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

void inline preCampute() {}

int n;
vector<vector<bool>> board;

bool possible(int r, int c)
{
	for (int i = 0; i < n; i++)
		if (board[i][c])
			return false;

	for (int i = 0; i < n; i++)
		if (board[r][i])
			return false;

	for (int i = r, j = c; i > -1 && j > -1; i--, j--)
		if (board[i][j])
			return false;

	for (int i = r, j = c; i < n && j < n; i++, j++)
		if (board[i][j])
			return false;

	for (int i = r, j = c; i < n && j > -1; i++, j--)
		if (board[i][j])
			return false;

	for (int i = r, j = c; i > -1 && j < n; i--, j++)
		if (board[i][j])
			return false;

	return true;
}

bool dfs(int remain)
{
	if (remain == 0)
		return true;

	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
		{
			if (possible(r, c))
			{
				board[r][c] = true;
				if (dfs(remain - 1))
					return true;
				board[r][c] = false;
			}
		}

	return false;
}

void inline solve()
{
	cin >> n;
	board = vector<vector<bool>>(n, vector<bool>(n, 0));
	bool tmp = dfs(n);
	cout << (tmp ? "YES" : "NO") << '\n';
	if (tmp)
	{
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
				cout << board[r][c] << ' ';
			cout << '\n';
		}
	}
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