// Time : O(n*(n+1)/2) amount of points in the triangle where n is the size of triangle
// Space : O(n*(n+1)/2)
// could be made faster by using c type array
int minimumTotal(vector<vector<int>> &triangle)
{
	int n = triangle.size();
	vector<vector<int>> dp(n);
	for (int i = 0; i < n; i++)
		dp[i] = vector<int>(i + 1, INT_MAX);
	dp[0][0] = triangle[0][0];

	for (int i = 0; i + 1 < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
		}
	}

	int mn = INT_MAX;
	for (int &e : dp[n - 1])
		mn = min(mn, e);
	return mn;
}

// Time : O(n*(n+1)/2) amount of points in the triangle where n is the size of triangle
// Space : O(n)
// optimized space
int minimumTotal(vector<vector<int>> &triangle)
{
	int n = triangle.size();
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = n - 1; i > -1; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}

	return dp[0];
}

// DFS with memoaztion
// Time : O(n*(n+1)/2) amount of points in the triangle where n is the size of triangle
// Space : O(n*(n+1)/2)
int dfs(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp, vector<vector<bool>> &found)
{
	if (r == triangle.size())
		return 0;
	if (found[r][c])
		return dp[r][c];

	int mn = dfs(triangle, r + 1, c, dp, found);
	mn = min(mn, dfs(triangle, r + 1, c + 1, dp, found));
	found[r][c] = true;
	return dp[r][c] = triangle[r][c] + mn;
}

int minimumTotal(vector<vector<int>> &triangle)
{
	int n = triangle.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	vector<vector<bool>> found(n, vector<bool>(n, false));

	return dfs(triangle, 0, 0, dp, found);
}