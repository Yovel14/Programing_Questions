// dp
int isSquare(int n)
{
	float root = sqrt(n);
	return root == int(root);
}
int solve(int n, int dp[])
{

	if (n == 0)
		return 0;
	if (n < 0)
		return INT_MAX;
	if (dp[n] != -1)
		return dp[n];

	if (isSquare(n))
		return dp[n] = 1;

	int mn = INT_MAX;
	int t = sqrt(n);
	for (int i = 1; i <= t; i++)
		mn = min(mn, solve(n - i * i, dp));
	return dp[n] = mn + 1;
}
int numSquares(int n)
{
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	return solve(n, dp);
}

// dp tabulation
int isSquare(int n)
{
	float root = sqrt(n);
	return root == int(root);
}
int numSquares(int n)
{
	int dp[n + 1];
	dp[1] = 1;
	int root;
	int mn;
	for (int i = 2; i <= n; i++)
	{
		if (isSquare(i))
		{
			dp[i] = 1;
			continue;
		}
		root = sqrt(i);
		mn = INT_MAX;
		for (int j = 1; j <= root; j++)
		{
			mn = min(mn, dp[i - j * j]);
		}
		dp[i] = mn + 1;
	}
	return dp[n];
}

// improved tabulation dp
bool inline isSquare(int n)
{
	float root = sqrt(n);
	return root == int(root);
}
int numSquares(int n)
{
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;

	int t = sqrt(n);
	int squares[t + 1];
	for (int i = 1; i <= t; i++)
		squares[i] = i * i;

	int root;
	int mn;
	for (int i = 2; i <= n; i++)
	{
		if (isSquare(i)) // this may not be necessary or even slow it down
		{
			dp[i] = 1;
			continue;
		}
		root = sqrt(i);
		mn = INT_MAX;
		for (int j = 1; j <= root; j++)
		{
			mn = min(mn, dp[i - squares[j]]);
		}
		dp[i] = mn + 1;
	}
	return dp[n];
}