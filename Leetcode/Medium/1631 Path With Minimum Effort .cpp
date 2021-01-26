// Time : O(R*C*log(mx)) R is length of rows; C is length of columns; and mx is 1000001
// Space : O(R*Clog(mx)) because of vesited array and queue  and they are made log(mx) times
// binary search over the answer
bool inline isgood(vector<vector<int>> &heights, int &limit)
{
	queue<pair<int, int>> q;
	q.push({0, 0});
	int R = heights.size();
	int C = heights[0].size();
	bool visited[R][C];
	memset(visited, 0, sizeof(visited));

	vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	int x;
	int y;
	int nx;
	int ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == R - 1 && y == C - 1)
			return true;
		for (pair<int, int> d : dir)
		{
			nx = x + d.first;
			ny = y + d.second;
			if (nx >= 0 && ny >= 0 && nx < R && ny < C && !visited[nx][ny])
			{
				if (abs(heights[x][y] - heights[nx][ny]) <= limit)
				{
					q.push({nx, ny});
					visited[nx][ny] = true;
				}
			}
		}
	}
	return false;
}
int minimumEffortPath(vector<vector<int>> &heights)
{
	int l = 0, r = 1000001;
	int mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (isgood(heights, mid))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}