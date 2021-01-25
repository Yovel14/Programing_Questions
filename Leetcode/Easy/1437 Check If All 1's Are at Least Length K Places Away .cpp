// Time : O(n)
// Space : O(1)
bool kLengthApart(vector<int> &nums, int k)
{
	if (k == 0) // not necessary
		return true;
	int n = nums.size();
	int last1 = -k - 1;
	for (int i = 0; i < n; i++)
		if (nums[i] == 1) // ==1 is not necessary
		{
			if (i - last1 - 1 < k)
				return false;
			last1 = i;
		}
	return true;
}