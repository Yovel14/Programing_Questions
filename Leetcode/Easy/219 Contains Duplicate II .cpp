// time : O(n)
// space : O(n)
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
	unordered_map<int, int> m;
	auto it = m.begin();
	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		it = m.find(nums[i]);
		if (it != m.end())
		{
			if (i - it->second <= k)
				return true;
			it->second = i;
		}
		else
			m.insert({nums[i], i});
	}

	return false;
}

// time : O(n*k)
// space : O(1)
bool containsNearbyDuplicate(vector<int> &nums, int k) // TLE
{
	int n = nums.size();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < i + k + 1 && j < n; j++)
			if (nums[i] == nums[j])
				return true;
	return false;
}