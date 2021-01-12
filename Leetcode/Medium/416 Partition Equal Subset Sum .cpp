bool canPartition(vector<int> &nums)
{
	int sum = 0;
	for (int &num : nums)
		sum += num;
	if (sum & 1)
		return false;

	sum = (sum >> 1);
	bool dp[sum + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for (int &num : nums)
	{
		for (int i = sum; i >= num && !dp[sum]; i--)
			dp[i] = dp[i] || dp[i - num];
		if (dp[sum])
			break;
	}
	return dp[sum];
}