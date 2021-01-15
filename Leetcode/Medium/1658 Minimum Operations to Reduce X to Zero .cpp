// TLE
// O(2^n) where n is length of nums
// o(n) because of recursion
void solve(vector<int> &nums, int x, int left, int right, int &ans, int count)
{
	if (x == 0)
		ans = min(ans, count);
	if (left > right)
		return;

	if (nums[left] <= x)
		solve(nums, x - nums[left], left + 1, right, ans, count + 1);

	if (nums[right] <= x)
		solve(nums, x - nums[right], left, right - 1, ans, count + 1);
}
int minOperations(vector<int> &nums, int x)
{
	int ans = INT_MAX;
	solve(nums, x, 0, nums.size() - 1, ans, 0);

	if (ans == INT_MAX)
		return -1;
	return ans;
}

//TLE
// O(n^2/2) = O(n^2) where n is length of nums; because of dp table nothing is calculated twice
// O(n) because of recursion
int solve(vector<int> &nums, int x, int l, int r, vector<vector<int>> &dp, int count, int &ans)
{
	if (x == 0)
	{
		ans = min(ans, count);
		return 0;
	}
	if (x < 0)
		return 100001;
	if (l > r)
		return 100001;

	if (count + 1 >= ans)
		return 100001;

	if (dp[l][r] != -1)
		return dp[l][r];
	return dp[l][r] = 1 + min(solve(nums, x - nums[l], l + 1, r, dp, count + 1, ans), solve(nums, x - nums[r], l, r - 1, dp, count + 1, ans));
}
int minOperations(vector<int> &nums, int x)
{
	int res = INT_MAX;
	vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
	int ans = solve(nums, x, 0, nums.size() - 1, dp, 0, res);
	if (ans > 100000)
		return -1;
	return ans;
}

// Time : O(n)
// space : O(n)
int minOperations(vector<int> nums, int x)
{
	int ans = -1;
	int sum = 0;
	int i = 0;
	int n = nums.size();
	unordered_map<int, int> m;

	m[0] = -1;
	for (; i < n && sum < x; i++)
		m[sum += nums[i]] = i;

	if (i == n)
	{
		if (sum == x)
			return n;
		if (sum < x)
			return -1;
	}

	if (sum == x)
		ans = i;

	sum = 0;
	auto it = m.begin();
	// to understand limit try dry runing the code on paper with test case num = {1,2,3,4,5} x = 10
	// you will see than when you search int the map after r < 3 there is not a sum because we stoped in the first loop(the prefix sum loop) because we don't add sum > x to the map
	for (int r = n - 1, limit = (ans != -1 ? n - ans : 0); r >= limit && sum <= x; r--)
	{
		it = m.find(x - (sum += nums[r]));
		if (it != m.end())
			ans = min((ans != -1 ? ans : n), it->second + 1 + n - r);
	}
	return ans;
}

// Time : O(n)
// Space : O(1)
int minOperations(vector<int> nums, int x)
{
	int n = nums.size();
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += nums[i];
	int target = sum - x;

	if (target < 0)
		return -1;
	if (target == 0)
		return n;

	int mx_size = -1;
	int sm = 0;
	for (int r = 0, l = 0; r < n; r++)
	{
		sm += nums[r];
		while (sm > target && l <= r)
			sm -= nums[l++];
		if (sm == target)
			mx_size = max(mx_size, r - l + 1);
	}

	if (mx_size != -1)
		return n - mx_size;
	return -1;
}
