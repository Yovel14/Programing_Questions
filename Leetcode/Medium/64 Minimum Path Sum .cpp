int minPathSum(vector<vector<int>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i != 0 || j != 0)
				grid[i][j] += min((i != 0 ? grid[i - 1][j] : INT_MAX), (j != 0 ? grid[i][j - 1] : INT_MAX));
		}
	return grid[n - 1][m - 1];
}