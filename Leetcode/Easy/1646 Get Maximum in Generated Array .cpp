// Time : O(n)
// Space : O(n)
int getMaximumGenerated(int n)
{
	// a[0] = 0;
	// a[1] = 1;
	// a[2 * i] = a[i] when 2 <= 2 * i <= n
	// a[2 * i + 1] = a[i] + a[i + 1] when 2 <= 2 * i + 1 <= n
	if (n == 0)
		return 0;
	int a[n + 1];
	a[0] = 0;
	a[1] = 1;
	int i = 1;
	int mx = 1;
	int limit;
	if (n & 1)
		limit = (n >> 1) + 1;
	else
		limit = (n >> 1);
	int index;
	for (; i < limit; i++)
	{
		index = (i << 1);
		mx = max(mx, a[index] = a[i]);
		mx = max(mx, a[index + 1] = a[i] + a[i + 1]);
	}
	index = (i << 1);
	if (index == n)
		mx = max(mx, a[index] = a[i]);
	return mx;
}

// dp
// Time : O(n)
// Space : O(n)
int solve(int index, vector<int> &dp, int &mx)
{
	if (index == 0 || index == 1)
		return index;
	if (index < 0)
		return INT_MIN;
	if (dp[index] != -1)
		return dp[index];
	if (index & 1) // odd
	{
		int temp = (index >> 1);
		int sum = 0;
		if (dp[temp] != -1)
			sum += dp[temp];
		else
			sum += solve(temp, dp, mx);
		if (dp[temp + 1] != -1)
			sum += dp[temp + 1];
		else
			sum += solve(temp + 1, dp, mx);
		mx = max(mx, sum);
		return dp[index] = sum;
	}
	dp[index] = solve((index >> 1), dp, mx);
	mx = max(mx, dp[index]);
	return dp[index];
}
int getMaximumGenerated(int n)
{
	if (n == 0)
		return 0;
	vector<int> dp(n + 1, -1);
	int mx = 1;
	for (int i = n; i > 1; i--)
		if (dp[i] == -1)
			solve(i, dp, mx);
	return mx;
}