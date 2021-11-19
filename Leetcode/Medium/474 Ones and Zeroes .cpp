// Time : O(n*m*l)
// Space : O(n*m*l)
int solve(vector<pair<int, int>> &v, int m, int n, int index, vector<vector<vector<int>>> &dp)
{
	if (index == v.size())
		return 0;
	if (n == 0 && m == 0)
		return 0;
	if (dp[index][m][n] != -1)
		return dp[index][m][n];
	int mx = solve(v, m, n, index + 1, dp); // don't use v[index]

	if (n >= v[index].second && m >= v[index].first)
		mx = max(mx, solve(v, m - v[index].first, n - v[index].second, index + 1, dp) + 1); // use v[index]

	return dp[index][m][n] = mx;
}
int findMaxForm(vector<string> &strs, int m, int n)
{

	int l = strs.size();
	vector<pair<int, int>> v(l); // {0, 1}
	for (int i = 0; i < l; i++)
	{
		int c0 = 0;
		int c1 = 0;
		for (char &c : strs[i])
		{
			if (c == '0')
				c0++;
			else
				c1++;
		}
		v[i].first = c0;
		v[i].second = c1;
	}

	vector<vector<vector<int>>> dp(l, vector<vector<int>>(m + 1, vector<int>(n + 1, -1))); // l,m,n
	return solve(v, m, n, 0, dp);
}

// Time : O(n*m*l)
// Space : O(n*m*l)
int findMaxForm(vector<string> &strs, int m, int n)
{
	int l = strs.size();
	int dp[l + 1][m + 1][n + 1]; // l,m,n
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= l; i++)
	{
		int c0 = 0;
		int c1 = 0;
		for (char &c : strs[i - 1])
		{
			if (c == '0')
				c0++;
			else
				c1++;
		}

		for (int k = 0; k <= m; k++)
			for (int z = 0; z <= n; z++)
			{
				if (k >= c0 && z >= c1)
					dp[i][k][z] = max(dp[i - 1][k][z], dp[i - 1][k - c0][z - c1] + 1);
				else
					dp[i][k][z] = dp[i - 1][k][z];
			}
	}

	return dp[l][m][n];
}

// improved space by l times over previous version of iterative dp
// Time : O(n*m*l)
// Space : O(n*m)
int findMaxForm(vector<string> &strs, int m, int n)
{
	int l = strs.size();
	int dp[m + 1][n + 1]; // l,m,n
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= l; i++)
	{
		int c0 = 0;
		int c1 = 0;
		for (char &c : strs[i - 1])
		{
			if (c == '0')
				c0++;
			else
				c1++;
		}

		for (int k = m; k >= c0; k--)
			for (int z = n; z >= c1; z--)
				dp[k][z] = max(dp[k][z], dp[k - c0][z - c1] + 1);
	}

	return dp[m][n];
}