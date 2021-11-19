// Time: O(log(n))
// Space: O(1)
int searchInsert(vector<int> &nums, int target)
{
	std::vector<int>::iterator foundNum = std::upper_bound(nums.begin(), nums.end(), target);

	if (foundNum != nums.begin() && *(foundNum - 1) == target)
	{
		return foundNum - nums.begin() - 1;
	}

	return foundNum - nums.begin();
}

// Time: O(log(n))
// Space: O(1)
int searchInsert(vector<int> &nums, int target)
{
	int low = 0;
	int high = nums.size() - 1;

	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);

		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return low;
}