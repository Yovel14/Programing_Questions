int Max(int &a, int &b)
{
	if (a > b)
		return a;
	return b;
}
int longestCommonSubsequence(string &a, string &b)
{
	int n = a.size();
	int m = b.size();

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = Max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	return dp[n][m];
}