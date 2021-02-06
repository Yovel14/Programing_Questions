// Time : O(nlog(n)) where n is the length nums
// Space : O(log(n)) log(n) log(n) is the space required in the average case
int findLHS(vector<int> &nums)
{
	if (nums.size() == 1)
		return 0;

	int mx = 0;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int cur_val = nums[0];
	int cur_length = 1;
	int prev_length = 0;

	for (int i = 1; i < n; i++)
	{
		if (nums[i] == nums[i - 1])
			cur_length++;
		else if (prev_length == 0)
		{
			if ((nums[i] - nums[i - 1]) == 1)
				prev_length = cur_length;
			cur_length = 1;
		}
		else
		{
			mx = max(mx, prev_length + cur_length);
			if ((nums[i] - nums[i - 1]) == 1)
				prev_length = cur_length;
			else
				prev_length = 0;
			cur_length = 1;
		}
	}
	if (prev_length != 0)
		return max(mx, prev_length + cur_length);
	return mx;
}

// better sorting implementation
int findLHS(vector<int> &nums)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int mx = 0;
	int r = 0, l = 0;
	while (r < n)
	{
		while (nums[r] - nums[l] > 1)
			l++;
		if (nums[r] - nums[l] == 1)
			mx = max(mx, r - l + 1);
		r++;
	}
	return mx;
}

// Time : O(n + k) where n is the length of nums and k is the number of unique numbers in nums
// Space : O(k)
int findLHS(vector<int> &nums)
{
	unordered_map<int, int> m;
	int mx = 0;
	unordered_map<int, int>::iterator it1;
	unordered_map<int, int>::iterator it2;

	for (int &n : nums)
		m[n]++;

	for (it1 = m.begin(); it1 != m.end(); it1++)
	{
		it2 = m.find(it1->first + 1);
		if (it2 != m.end())
			mx = max(mx, it1->second + it2->second);
	}
	return mx;
}

// Time : O(n)
// Space : O(n)
int findLHS(vector<int> &nums)
{
	unordered_map<int, int> m;
	int mx = 0;
	unordered_map<int, int>::iterator it1;
	unordered_map<int, int>::iterator it2;
	unordered_map<int, int>::iterator it3;
	for (int &n : nums)
	{
		it1 = m.find(n);
		it2 = m.find(n + 1);
		it3 = m.find(n - 1);
		if (it1 == m.end())
		{
			m.insert({n, 1});
			if (it2 != m.end())
				mx = max(mx, it2->second + 1);
			if (it3 != m.end())
				mx = max(mx, it3->second + 1);
		}
		else
		{
			it1->second++;
			if (it2 != m.end())
				mx = max(mx, it1->second + it2->second);
			if (it3 != m.end())
				mx = max(mx, it1->second + it3->second);
		}
	}
	return mx;
}

// TLE
// Time : O(n)
// Space : O(1)
// could be improved with a hash set
int findLHS(vector<int> &nums)
{
	int ans = 0;
	int mn;
	bool flag;
	int count;
	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		flag = false;
		count = 0;
		mn = nums[i];
		for (int j = 0; j < n; j++)
		{
			if (nums[j] == mn)
				count++;
			else if (nums[j] + 1 == mn)
			{
				count++;
				flag = true;
			}
		}
		if (flag)
			ans = max(ans, count);
	}
	return ans;
}