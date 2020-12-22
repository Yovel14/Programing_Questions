int removeDuplicates(vector<int> &nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	// i represent the start of the duplicates and j finds the first who is not a duplicate
	int i = 0;
	for (int j = 1; j < n; ++j)
		if (nums[i] != nums[j])
			nums[++i] = nums[j]; // notice ++i

	return i + 1;
}