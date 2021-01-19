// Time : O(n)
// Space : O(n)
int maxOperations(vector<int> &nums, int k)
{
	sort(nums.begin(), nums.end());
	int r = nums.size() - 1;
	int l = 0;
	int count = 0;
	int sm;
	while (l < r)
	{
		sm = nums[l] + nums[r];
		if (sm == k)
		{
			count++;
			l++;
			r--;
		}
		else if (sm > k)
			r--;
		else
			l++;
	}
	return count;
}

// Time : O(nlog(n))
// space : O(1)
int maxOperations(vector<int> &nums, int k)
{
	unordered_map<int, int> m; // map of the amount of times each numbers apears till that point(cosidering  I am removing)
	int count = 0;
	auto it = m.begin();
	for (int &num : nums)
	{
		it = m.find(k - num);
		if (it != m.end() && it->second)
		{
			it->second--;
			count++;
		}
		else
		{
			it = m.find(num);
			if (it != m.end())
				it->second++;
			else
				m[num] = 1;
		}
	}
	return count;
}