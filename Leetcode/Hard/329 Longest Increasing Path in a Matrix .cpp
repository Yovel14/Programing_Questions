// Memoization dp
// the reason dp works here is because going from one to another does not work both ways
// Time : O(R*C)
// Space : O(R*cC)
int dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<bool>> &seen, vector<vector<int>> &dp)
{
	if (r >= matrix.size() || r < 0 || c == matrix[0].size() || c < 0)
		return 0;
	if (dp[r][c] != -1)
		return dp[r][c];
	int mx = 1;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (i != j && -i != j)
			{
				int nr = r + i;
				int nc = c + j;
				if (nc > -1 && nr > -1 && nr < matrix.size() && nc < matrix[0].size() && !seen[nr][nc] && matrix[nr][nc] > matrix[r][c])
				{
					seen[nr][nc] = true;
					mx = max(mx, 1 + dfs(matrix, nr, nc, seen, dp));
					seen[nr][nc] = false;
				}
			}
	return dp[r][c] = mx;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
	int R = matrix.size();
	if (R == 0)
		return 0;
	int C = matrix[0].size();
	int mx = 0;
	vector<vector<bool>> seen(R, vector<bool>(C, 0));
	vector<vector<int>> dp(R, vector<int>(C, -1));
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
			mx = max(mx, dfs(matrix, r, c, seen, dp));
	}
	return mx;
}

// Improved on space a bit
// Time : O(R*C)
// Space : O(R*C)
int dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp, int prev)
{
	if (r >= matrix.size() || r < 0 || c == matrix[0].size() || c < 0 || matrix[r][c] <= prev)
		return 0;
	if (dp[r][c] != -1)
		return dp[r][c];
	return dp[r][c] = 1 + max({dfs(matrix, r + 1, c, dp, matrix[r][c]), dfs(matrix, r, c + 1, dp, matrix[r][c]), dfs(matrix, r - 1, c, dp, matrix[r][c]), dfs(matrix, r, c - 1, dp, matrix[r][c])});
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
	int R = matrix.size();
	if (R == 0)
		return 0;
	int C = matrix[0].size();
	int mx = 0;

	vector<vector<int>> dp(R, vector<int>(C, -1));
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
			mx = max(mx, dfs(matrix, r, c, dp, INT_MIN));
	}
	return mx;
}