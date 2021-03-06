int longestCommonSubsequence(string a, string b)
{
	int n = a.size();
	int m = b.size();

	int dp[n + 1][m + 1];
	//for (int i = 0; i < n + 1; i++)
	//    for (int j = 0; j < m + 1; j++)
	//        dp[i][j] = 0;
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	return dp[n][m];
}