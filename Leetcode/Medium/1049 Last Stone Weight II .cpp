// this solutions works because:
// (4-2)-(8-7) = (4-2) + (7-8) = (4 +7)  -(8 + 2)
// as you can see above the numbers can be divided into two groups and at the end they are subtructed in abs value
vector<vector<int>> dp;
int solve(vector<int> &stones, int i, int s1, int s2) // to understand dp table do a dry run with any stone vector
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

// same as knapsackproblem
// Time : O(n * sum/2) where n is length of stones and sum is the total sum of the stones
// Space : O(n * sum/2)
int lastStoneWeightII(vector<int> &stones)
{
	// (4-2)-(8-7) = (4-2) + (7-8) = (4 +7)  -(8 + 2)
	// as you can see above the numbers can be divided into two groups and at the end they are subtructed in abs value
	// so the question becomes divide the array into two halfs so their difference will be minimal
	// we find the first half by finding a subset which is closest to half lets call it s1
	// lets call the total sum s
	// lets s2 be the second half
	// to find the second half we can use than s = s1 + s2
	// thus s1 = s-s2
	// so s1-s2 = s-s2-s2

	int sum = 0;
	for (int &it : stones)
		sum += it;

	int half = (sum >> 1);

	int n = stones.size();
	vector<vector<int>> dp(n, vector<int>(half + 1, 0));
	for (int i = 0; i <= half; i++)
		if (i >= stones[0])
			dp[0][i] = stones[0];
	for (int si = 1; si < n; si++)
	{
		for (int i = 1; i <= half; i++)
		{
			if (stones[si] > i)
				dp[si][i] = dp[si - 1][i];
			else
				dp[si][i] = max(dp[si - 1][i], dp[si - 1][i - stones[si]] + stones[si]);
		}
	}
	return sum - dp[n - 1][half] - dp[n - 1][half];
}

// checks what is the maximum sum smaller than half of the total sum I can get to
int lastStoneWeightII(vector<int> &stones)
{
	int sum = 0;
	for (int &it : stones)
		sum += it;
	int half = (sum >> 1);
	int n = stones.size();
	int mx = 0;
	vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, 0));

	for (int i = 0; i < n; i++)
		dp[i][0] = true;
	for (int si = 1; si <= n; si++)
	{
		for (int ps = 1; ps <= half; ps++)
		{
			if (dp[si - 1][ps] || (ps >= stones[si - 1] && dp[si - 1][ps - stones[si - 1]]))
			{
				dp[si][ps] = true;
				mx = max(mx, ps);
			}
		}
	}
	return sum - mx - mx;
}