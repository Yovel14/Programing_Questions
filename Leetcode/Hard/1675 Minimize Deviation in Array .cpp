// prority_queue
// Time : O(n * log2(mx)) n is length of nums and mx is the mx value in numes
// Space : O(n)
int minimumDeviation(vector<int> nums)
{
	// the deviation could also be defined as the max_value - min_value
	// so add as much as you can to the min value and reduce the max value as much as you can
	// do this n times and the result will be the mx_value-mn_value

	int mn = INT_MAX;
	int t;
	int dev;

	for (int &n : nums)
	{
		if (n & 1)
			n <<= 1;

		if (n < mn)
			mn = n;
	}
	priority_queue<int> pq(nums.begin(), nums.end());

	dev = pq.top() - mn;
	while ((pq.top() & 1 ^ 1))
	{
		t = pq.top();
		pq.pop();
		t >>= 1;
		pq.push(t);
		mn = min(mn, t);
		dev = min(dev, pq.top() - mn);
	}

	return dev;
}

// set
// Time : O(n * log2(mx)) n is amount of unike numbers and mx is the mx value in numes
// Space : O(n)
int minimumDeviation(vector<int> nums)
{
	// the deviation could also be defined as the max_value - min_value
	// so add as much as you can to the min value and reduce the max value as much as you can
	// do this n times and the result will be the mx_value-mn_value
	int mx;
	int dev;
	set<int, greater<int>> s;
	for (int &n : nums)
	{
		if (n & 1)
			s.insert(n << 1);
		else
			s.insert(n);
	}

	set<int, greater<int>>::iterator it = s.begin();
	mx = *it;
	dev = mx - (*s.rbegin());
	while (mx & 1 ^ 1)
	{
		s.erase(it);
		mx >>= 1;
		s.insert(mx);
		it = s.begin();
		mx = *it;
		dev = min(dev, mx - (*s.rbegin()));
	}
	return dev;
}