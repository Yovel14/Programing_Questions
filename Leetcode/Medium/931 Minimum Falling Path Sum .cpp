int minFallingPathSum(vector<vector<int>> &a)
{
	int n = a.size();
	int base_val;
	for (int r = 1; r < n; r++)
		for (int c = 0; c < n; c++)
		{
			base_val = a[r][c];
			a[r][c] += a[r - 1][c];

			if (c != 0)
				a[r][c] = min(a[r][c], a[r - 1][c - 1] + base_val);
			if (c != n - 1)
				a[r][c] = min(a[r][c], a[r - 1][c + 1] + base_val);
		}
	int mn = INT_MAX;
	for (int i = 0; i < n; i++)
		mn = min(mn, a[n - 1][i]);
	return mn;
}