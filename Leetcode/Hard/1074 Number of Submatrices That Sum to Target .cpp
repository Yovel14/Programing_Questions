// Time : O(R^2*c^2)
// Space : O(R*C)
int numSubmatrixSumTarget(vector<vector<int>> matrix, int target)
{
	int R = matrix.size();
	int C = R ? matrix[0].size() : 0;

	for (int r = 1; r < R; r++)
		for (int c = 0; c < C; c++)
			matrix[r][c] += matrix[r - 1][c];

	int count = 0;

	for (int sr = 0; sr < R; sr++)
	{
		for (int sc = 0; sc < C; sc++)
		{
			for (int r = sr; r < R; r++)
			{
				int sum = 0;
				for (int c = sc; c < C; c++)
				{
					sum += matrix[r][c];
					if (sr > 0)
						sum -= matrix[sr - 1][c];
					if (sum == target)
						count++;
				}
			}
		}
	}

	return count;
}

// faster than the solution above but they have the same idea to do so I changed vector<vector<int>> to int[][] but they have the same complexity
int numSubmatrixSumTarget(vector<vector<int>> mat, int target)
{
	int R = mat.size();
	int C = R ? mat[0].size() : 0;
	int matrix[R][C];
	for (int c = 0; c < C; c++)
		matrix[0][c] = mat[0][c];

	for (int r = 1; r < R; r++)
		for (int c = 0; c < C; c++)
			matrix[r][c] = matrix[r - 1][c] + mat[r][c];

	int count = 0;

	for (int sr = 0; sr < R; sr++)
	{
		for (int sc = 0; sc < C; sc++)
		{
			for (int r = sr; r < R; r++)
			{
				int sum = 0;
				for (int c = sc; c < C; c++)
				{
					sum += matrix[r][c];
					if (sr > 0)
						sum -= matrix[sr - 1][c];
					if (sum == target)
						count++;
				}
			}
		}
	}

	return count;
}

// Time : O(r*C + C*C*R) = O(R*C + C^2*R)
// Space : O(R*C)
int numSubmatrixSumTarget(vector<vector<int>> matrix, int target)
{
	int R = matrix.size();
	int C = R ? matrix[0].size() : 0;

	for (int r = 0; r < R; r++)
		for (int c = 1; c < C; c++)
			matrix[r][c] += matrix[r][c - 1];

	int count = 0;
	for (int start = 0; start < C; start++)
		for (int end = start; end < C; end++)
		{
			unordered_map<int, int> m;
			m[0]++;
			int sum = 0;
			for (int r = 0; r < R; r++)
			{
				sum += matrix[r][end];
				if (start > 0)
					sum -= matrix[r][start - 1];

				count += m[sum - target];

				m[sum]++;
			}
		}

	return count;
}