// breadth for search
// Time : O(n)
// Space : O(n) // could be reduced by instead of using an array to check if visited just turn in the grid the 0 to 1 like in the code below

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
	int n = grid.size();
	if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
		return -1;
	if (n == 1)
		return 1;
	queue<pair<int, int>> q; // r,c
	bool visited[n][n];
	memset(visited, 0, sizeof(visited));
	visited[0][0] = true;

	q.push({0, 0});
	int k = 1;
	int tmp_length = 1;
	int cur_length;
	int dir[16] = {-1, -1, 0, -1, 1, -1, -1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
	int c, r, nc, nr;
	while (!q.empty())
	{
		cur_length = tmp_length;
		tmp_length = 0;
		while (cur_length--)
		{
			r = q.front().first;
			c = q.front().second;
			q.pop();
			for (int i = 0; i < 16; i += 2)
			{
				nr = r + dir[i];
				nc = c + dir[i + 1];

				if (nc < n && nc > -1 && nr > -1 && nr < n && grid[nr][nc] == 0 && !visited[nr][nc])
				{
					if (nr == n - 1 && nc == n - 1)
						return k + 1;
					visited[nr][nc] = true;
					q.push({nr, nc});
					tmp_length++;
				}
			}
		}
		k++;
	}
	return -1;
}

// Time : O(n)
// Space : O(1)
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
	// breadth for search
	int n = grid.size();
	if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
		return -1;
	if (n == 1)
		return 1;
	queue<pair<int, int>> q; // c,y

	q.push({0, 0});
	int k = 1;
	int tmp_length = 1;
	int cur_length;
	int dir[16] = {-1, -1, 0, -1, 1, -1, -1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
	int c, r, nc, nr;
	while (!q.empty())
	{
		cur_length = tmp_length;
		tmp_length = 0;
		while (cur_length--)
		{
			r = q.front().first;
			c = q.front().second;
			q.pop();
			for (int i = 0; i < 16; i += 2)
			{
				nr = r + dir[i];
				nc = c + dir[i + 1];

				if (nc < n && nc > -1 && nr > -1 && nr < n && grid[nr][nc] == 0)
				{
					if (nr == n - 1 && nc == n - 1)
						return k + 1;
					grid[nr][nc] = 1;
					q.push({nr, nc});
					tmp_length++;
				}
			}
		}
		k++;
	}
	return -1;
}