// Time : O(n * target) where n is the length of nums
// Space : O(target)
int combinationSum4(vector<int> nums, int target)
{
	unsigned int dp[target + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int n = nums.size();
	sort(nums.begin(), nums.end());

	for (unsigned int i = 0; i < target; i++)
		if (dp[i])
			for (int &num : nums)
			{
				if (i + num > target)
					break;
				dp[i + num] += dp[i];
			}
	return dp[target];
}

// Time : O(n * target) where n is the length of nums
// Space : O(target)
int dfs(vector<int> &nums, int target, unsigned int dp[])
{
	if (target == 0)
		return 1;
	if (dp[target] != -1)
		return dp[target];
	int count = 0;
	for (int &n : nums)
	{
		if (n > target)
			break;
		count += dfs(nums, target - n, dp);
	}
	return dp[target] = count;
}
int combinationSum4(vector<int> nums, int target)
{
	unsigned int dp[target + 1];
	memset(dp, -1, sizeof(dp));
	sort(nums.begin(), nums.end());
	return dfs(nums, target, dp);
}