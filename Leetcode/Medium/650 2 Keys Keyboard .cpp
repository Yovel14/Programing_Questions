int dp[1001][1001];
int solve(int &n, int count, int copy, int val)
{
	if (val > n || count > n)
		return INT_MAX;
	if (val == n)
		return count;

	if (dp[count][val] != -1)
		return dp[count][val];

	return dp[count][val] = min(solve(n, count + 1, copy, val + copy), solve(n, count + 2, val, (val << 1)));
}

int minSteps(int n)
{
	if (n == 1)
		return 0;
	memset(dp, -1, sizeof(dp));
	return solve(n, 1, 1, 1);
}