// Time : O(2^n)
// Space : O(n)
int solve(vector<int> &nums, int s, int index, int sum)
{
	if (index == nums.size())
		return sum == s;
	return solve(nums, s, index + 1, sum + nums[index]) + solve(nums, s, index + 1, sum - nums[index]);
}
int findTargetSumWays(vector<int> &nums, int s)
{
	return solve(nums, s, 0, 0);
}

// dp
// Time : O(n*n) : n*n and not n*sum where sum is the sum of all the numbers in nums because we don't use all the numbers between 0 and sum we use only does which there sum is posible to get to with the numbers in nums
// space : O(n*sum) where sum is the sum of all the numbers in nums
int solve(vector<int> &nums, int s, int index, int sum, vector<vector<int>> &pdp, vector<vector<int>> &ndp)
{
	if (index == nums.size())
		return sum == s;

	if (sum < 0)
	{
		if (ndp[index][abs(sum)] != -1)
			return ndp[index][abs(sum)];
		return ndp[index][abs(sum)] = solve(nums, s, index + 1, sum + nums[index], pdp, ndp) + solve(nums, s, index + 1, sum - nums[index], pdp, ndp);
	}

	if (pdp[index][sum] != -1)
		return pdp[index][sum];
	return pdp[index][sum] = solve(nums, s, index + 1, sum + nums[index], pdp, ndp) + solve(nums, s, index + 1, sum - nums[index], pdp, ndp);
}
int findTargetSumWays(vector<int> &nums, int s)
{
	int sm = 0;
	for (int &num : nums)
		sm += num;

	vector<vector<int>> pdp(nums.size(), vector<int>(sm + 1, -1));
	vector<vector<int>> ndp(nums.size(), vector<int>(sm + 1, -1));

	return solve(nums, s, 0, 0, pdp, ndp);
}

// dp
// Time : O(n * sum)
// Space : O(n* sum)
int findTargetSumWays(vector<int> &nums, int s)
{
	// the idea behind this soluiton is to find until each point what is the amount of times I can get to this sum from nums int the previous indexes
	if (s > 1000)
		return 0;
	int total = 0;
	for (int &num : nums)
		total += num;
	if (s > total || s < -total)
		return 0;

	vector<vector<int>> dp(nums.size(), vector<int>((total << 1) + 1, 0));
	dp[0][nums[0] + total] = 1;
	dp[0][-nums[0] + total] += 1;
	int n = nums.size();
	for (int i = 1; i < n; i++)
		for (int sum = -total; sum <= total; sum++)
		{
			if (dp[i - 1][sum + total] != 0)
			{
				dp[i][sum + nums[i] + total] += dp[i - 1][sum + total];
				dp[i][sum - nums[i] + total] += dp[i - 1][sum + total];
			}
		}
	return dp[n - 1][s + total];
}

// Time : O(n*sum)
// Space : O(sum)
int findTargetSumWays(vector<int> &nums, int s)
{
	// the idea behind this soluiton is to find until each point what is the amount of times I can get to this sum from nums int the previous indexes
	if (s > 1000)
		return 0;
	int total = 0;
	for (int &num : nums)
		total += num;
	if (s > total || s < -total)
		return 0;

	vector<int> dp((total << 1) + 1, 0);
	vector<int> next;
	dp[nums[0] + total] = 1;
	dp[-nums[0] + total] += 1;
	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		next = vector<int>((total << 1) + 1, 0);
		for (int sum = -total; sum <= total; sum++)
		{
			if (dp[sum + total] != 0) // for checking overflow and underflow
			{
				next[sum + nums[i] + total] += dp[sum + total];
				next[sum - nums[i] + total] += dp[sum + total];
			}
		}
		dp = next;
	}
	return dp[s + total];
}

// TLE; unlike the first this does not pass because of pushing 2^n times to a vector thus solwing it down and it being slower than the first 2^n solution
// Time : O(2^n)
// Space : (2^n)
int findTargetSumWays(vector<int> &nums, int s)
{
	vector<int> cur;
	vector<int> temp = {0};
	for (int &num : nums)
	{
		cur = temp;
		temp = {};
		for (int &c : cur)
			temp.push_back(c + num);
		for (int &c : cur)
			temp.push_back(c - num);
	}

	int count = 0;
	for (int &num : temp)
		if (num == s)
			count++;
	return count;
}
