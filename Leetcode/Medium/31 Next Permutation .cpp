// Time : O(n)
// Space : O(1)
void reverse(vector<int> &nums, int l, int r)
{
	while (l < r)
		swap(nums[l++], nums[r--]);
}
void nextPermutation(vector<int> &nums)
{
	int n = nums.size();
	if (n == 1)
		return;

	int i = n - 2;
	while (i >= 0 && nums[i] >= nums[i + 1])
		i--;

	if (i >= 0)
	{
		int j = n - 1;
		while (j > i && nums[j] <= nums[i]) // this could be improved with binary search as you can see below
			j--;
		swap(nums[i], nums[j]);
	}

	reverse(nums, i + 1, n - 1);
}

// Time : O(n)
// Space : O(1)
int upper_bound(vector<int> &nums, int l, int r, int v)
{
	int mid;
	int p = r;
	while (l <= r)
	{
		mid = l + ((r - l) >> 1);
		if (nums[mid] > v)
		{
			p = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return p;
}
void reverse(vector<int> &nums, int l, int r)
{
	while (l < r)
		swap(nums[l++], nums[r--]);
}
void nextPermutation(vector<int> &nums)
{
	int n = nums.size();
	if (n == 1)
		return;

	int i = n - 2;
	while (i >= 0 && nums[i] >= nums[i + 1])
		i--;

	if (i >= 0)
	{
		swap(nums[i], nums[upper_bound(nums, i + 1, n - 1, nums[i])]);
	}

	reverse(nums, i + 1, n - 1);
}