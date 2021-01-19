// Time : O(nlog(n))
// Space : O(1)
int findKthLargest(vector<int> &nums, int k)
{
	sort(nums.rbegin(), nums.rend());
	return nums[k - 1];
}

// Time : Average : O(log(n)); Worst case : O(n^2/n) = O(n) because worst case it does n^2 of over all parts but I am runing over only one side thus divided by n
// Space : O(1)
void Choose_Pivot(vector<int> &v, int &l, int &r) // sets pivot as the the value on r index. the pivot will be the value which is the middle between l,r,(r+l)/2
{
	if (l != r)
	{
		int mid = l + ((r - l) >> 1); // mid index (the same as (r+l)/2 just this prevents integer overflow)
		if ((v[mid] <= v[l] && v[mid] >= v[r]) || (v[mid] >= v[l] && v[mid] <= v[r]))
			swap(v[mid], v[r]);
		if ((v[l] <= v[mid] && v[l] >= v[r]) || (v[l] >= v[mid] && v[l] <= v[r]))
			swap(v[l], v[r]);
		// v[r] is mid so leave it
	}
}
int findKthLargest(vector<int> &nums, int k)
{
	// the Idea of quick sort could be used to solve this in log(n) time
	k = nums.size() - k;
	int low = 0;
	int high = nums.size() - 1;
	int pivot = -1;
	int j;
	while (pivot != k)
	{
		Choose_Pivot(nums, low, high);
		pivot = high;
		int j = low;					  // last bigger location
		for (int i = low; i < pivot; i++) // i finds smaller numbers
			if (nums[i] <= nums[pivot])
				swap(nums[i], nums[j++]);
		swap(nums[j], nums[pivot]);
		pivot = j;
		if (pivot > k)
			high = pivot - 1;
		else
			low = pivot + 1;
	}
	return nums[pivot];
}

// Time : O(n + k)
// Space : O(n)
int findKthLargest(vector<int> &nums, int k)
{
	priority_queue<int> pq(less<int>(), nums);
	k--;
	while (k--)
		pq.pop();
	return pq.top();
}