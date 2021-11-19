// Time : O(n^2)
// Space : O(1)
void rotate(vector<vector<int>> &matrix)
{
	int n = matrix.size();

	//
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}

	// reverse
	for (int i = 0; i < n; i++)
	{
		for (int j = n / 2 - 1; j >= 0; j--)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[i][n - 1 - j];
			matrix[i][n - 1 - j] = tmp;
		}
	}
}