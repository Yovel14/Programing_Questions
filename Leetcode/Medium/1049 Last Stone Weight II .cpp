
// this solutions works because:
// (4-2)-(8-7) = (4-2) + (7-8) = (4 +7)  -(8 + 2)
// as you can see above the numbers can be divided into two groups and at the end they are subtructed in abs value
vector<vector<int>> dp;
int solve(vector<int> &stones, int i, int s1, int s2)
{
	if (i == stones.size())
		return abs(s1 - s2);
	if (dp[i][s1] != -1)
		return dp[i][s1];
	if (dp[i][s2] != -1)
		return dp[i][s2];

	return dp[i][s1] = dp[i][s2] = min(solve(stones, i + 1, s1 + stones[i], s2), solve(stones, i + 1, s1, s2 + stones[i]));
}
int lastStoneWeightII(vector<int> &stones)
{
	int sum = 0;
	for (int &it : stones)
		sum += it;
	dp = vector<vector<int>>(sum + 1, vector<int>(sum + 1, -1));
	return solve(stones, 0, 0, 0);
}