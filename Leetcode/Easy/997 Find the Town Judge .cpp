// Time : O(N) where N is length of trust
// Space : O(n) where n is the number of people in town
int findJudge(int n, vector<vector<int>> &trust)
{
	int p[n + 1];
	memset(p, 0, sizeof(p));
	int N = trust.size();
	for (int i = 0; i < N; i++)
	{
		p[trust[i][0]]--;
		p[trust[i][1]]++;
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == n - 1)
			return i;
	return -1;
}