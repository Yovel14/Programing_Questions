// Time : O(n * log2(m))
// Space : O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	int s;
	int n = matrix.size(), m = matrix[0].size();
	int l, h, mid;
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][0] > target)
			return false;
		l = 0, h = m - 1;
		while (l <= h)
		{
			mid = l + ((h - l) >> 1);
			if (matrix[i][mid] == target)
				return true;
			else if (matrix[i][mid] > target)
				h = mid - 1;
			else
				l = mid + 1;
		}
	}
	return false;
}

// Time : O(sqrt(R^2 + C^2)) which is less than O(R+C)
// Space : O(1)
// this solution works because matrix[r][c] < matrix[r+1][c+1] and matrix[r][c] < matrix[r+1][c] and matrix[r][c] < matrix[r][c+1] for all r,c (assuming the indexes are not overflowing)
// this could be improved by searching for the minimum start which is possible and the maximum end which is possible and searching only between them
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	int R = matrix.size(), C = R ? matrix[0].size() : 0;
	int r = 0, c = C - 1;

	while (r < R && c != -1)
	{
		if (matrix[r][c] == target)
			return true;
		if (matrix[r][c] < target)
			r++;
		else
			c--;
	}

	return false;
}