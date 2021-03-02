// Time : O(n)
// Space : O(n)
vector<int> findErrorNums(vector<int> nums)
{
	unordered_set<int> u;
	int twice = 0;
	int n = nums.size();
	int sum = 0;
	for (int &e : nums)
	{
		if (!twice)
		{
			if (u.find(e) != u.end())
				twice = e;
			u.insert(e);
		}
		sum += e;
	}
	sum -= twice;
	return {twice, n * (n + 1) / 2 - sum};
}

// Time  : O(n)
// Space : O(n)
vector<int> findErrorNums(vector<int> nums)
{
	int n = nums.size();
	bool b[n + 1];
	memset(b, 0, sizeof(b));
	int a1 = 0;
	int a2;
	for (int &e : nums)
	{
		if (b[e])
			a1 = e;
		b[e] ^= 1;
	}

	for (int i = 1; i <= n; i++)
		if (b[i] == false && i != a1)
		{
			a2 = i;
			break;
		}
	return {a1, a2};
}

// Time : O(n)
// Space : O(1)
vector<int> findErrorNums(vector<int> nums)
{
	int n = nums.size();

	int a1 = 0;
	int a2;
	int index;
	for (int i = 0; i < n; i++)
	{
		index = abs(nums[i]) - 1;
		if (nums[index] < 0)
			a1 = index + 1;
		else
			nums[index] = -nums[index];
	}

	for (int i = 0; i < n; i++)
	{
		if (nums[i] > 0)
			a2 = i + 1;
		else
			nums[i] = -nums[i];
	}

	return {a1, a2};
}