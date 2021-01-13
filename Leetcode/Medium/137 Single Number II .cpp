// time : O(n)
// space : O(1)
int singleNumber(vector<int> &nums)
{
	int once = 0;
	int twice = 0;
	int three = 0;

	for (int &n : nums)
	{
		twice ^= once & n;
		/*
            put in twice whay apears in once and n
            
            */
		once ^= n & (~twice);
		/*
            put in once what appears int n and not in twice
            or remove whay apears in n not in twice (not in because it was removed)
            */
	}

	return once;
}

// time : O(n)
// space O(n)
int singleNumber(vector<int> &nums)
{
	unordered_map<int, int> m;
	auto it = m.begin();

	for (int &num : nums)
	{
		it = m.find(num);
		if (it != m.end())
			it->second++;
		else
			m.insert({num, 1});
	}
	for (auto it2 : m)
		if (it2.second == 1)
			return it2.first;
	return -1;
}

// time : O(nlog(n))
// space : O(1)
int singleNumber(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size() - 1;

	for (int i = 0; i < n; i += 3)
		if (nums[i] != nums[i + 1])
			return nums[i];

	return nums[n];
}