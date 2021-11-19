// Time : O(n*m) where n is the size of wall and m is the sum of elements in vector wall[0]
// Space : O(m)
int leastBricks(vector<vector<int>> &wall)
{
	int n = wall.size();
	unordered_map<int, int> wallCount;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int m = wall[i].size() - 1;
		for (int j = 0; j < m; j++)
		{
			sum += wall[i][j];
			wallCount[sum]++;
		}
	}

	int ans = 0;
	for (unordered_map<int, int>::iterator it = wallCount.begin(); it != wallCount.end(); it++)
		ans = max(ans, it->second);

	return n - ans;
}