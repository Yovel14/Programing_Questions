// Time : O(nlog2(n))
// Space : O(n)
int findUnsortedSubarray(vector<int> &nums)
{
	vector<int> nc = nums; // make a copy of nums
	sort(nc.begin(), nc.end());
	int l = 0, r = nums.size() - 1;
	while (l < r)
	{
		if (nums[l] == nc[l])
			l++;
		else if (nums[r] == nc[r])
			r--;
		else
			break;
	}

	return r == l ? 0 : r - l + 1;
}

// stack
// Time : O(n)
// Space : O(n)
int findUnsortedSubarray(vector<int> &nums)
{
	int n = nums.size();
	stack<int> s;
	int r = 0, l = n;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && nums[s.top()] > nums[i])
		{
			l = min(l, s.top());
			s.pop();
		}
		s.push(i);
	}

	r = {};
	for (int i = n - 1; i != -1; i--)
	{
		while (!s.empty() && nums[s.top()] < nums[i])
		{
			r = max(r, s.top());
			s.pop();
		}
		s.push(i);
	}

	return r < l ? 0 : r - l + 1;
}

// TLE
// Time : O(n^2)
// Space : O(1)
int findUnsortedSubarray(vector<int> &nums)
{
	int n = nums.size();
	int r = 0, l = n;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (nums[j] < nums[i])
			{
				r = max(r, j);
				l = min(l, i);
			}
		}

	return l > r ? 0 : r - l + 1;
}

// Time : O(n)
// Space : O(1)
// find the front and back indexes than are out of order
int findUnsortedSubarray(vector<int> &nums)
{
	int mn = nums.back();
	int mx = nums.front();
	int front_out_of_order = nums.size();
	int back_out_of_order = -1;
	for (int j = nums.size() - 2, i = 1; j != -1; j--, i++)
	{
		if (nums[j] > mn)
			front_out_of_order = j;
		mn = min(mn, nums[j]);

		if (nums[i] < mx)
			back_out_of_order = i;
		mx = max(mx, nums[i]);
	}
	return front_out_of_order > back_out_of_order ? 0 : back_out_of_order - front_out_of_order + 1;
}