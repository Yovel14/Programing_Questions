// Time : O(m*n * log(min(n,m)))
// Space : O(min(m,n))
vector<vector<int>> diagonalSort(vector<vector<int>> mat)
{
	int rows = mat.size();
	int columns = mat[0].size();
	int a[rows + columns];
	int p;

	for (int col = 0; col < columns; col++)
	{
		p = 0;
		for (int row = 0; row < rows && col + row < columns; row++)
			a[p++] = mat[row][row + col];
		sort(a, a + p);

		p = 0;
		for (int row = 0; row < rows && col + row < columns; row++)
			mat[row][row + col] = a[p++];
	}

	for (int row = 1; row < rows; row++)
	{
		p = 0;
		for (int col = 0; col < columns && col + row < rows; col++)
			a[p++] = mat[row + col][col];
		sort(a, a + p);

		p = 0;
		for (int col = 0; col < columns && col + row < rows; col++)
			mat[row + col][col] = a[p++];
	}

	return mat;
}