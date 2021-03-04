// Time : O(n)
// Space : O(1)
int missingNumber(vector<int> &nums)
{
	int sum = 0;

	for (int &e : nums)
		sum += e;
	int n = nums.size();
	return n * (n + 1) / 2 - sum;
}

// Time : O(n)
// Space : O(1)
int missingNumber(vector<int> &nums)
{
	int missing = 0;
	int n = nums.size();

	for (int i = 1; i <= n; i++)
		missing ^= i;
	for (int &e : nums)
		missing ^= e;

	return missing;
}

// Time : O(nlog2(n))
// Space : O(1)
int missingNumber(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < n; i++)
		if (nums[i] != i)
			return i;
	return n;
}

// Hash set is also a valid solution which runs in O(n) and space O(n)