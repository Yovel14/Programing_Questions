// two pointer
// Time : O(n)
// Space: O(n)
vector<int> sortedSquares(vector<int> &nums)
{
	int high = nums.size() - 1;
	int low = 0;
	vector<int> ans = vector<int>(nums.size());

	for (int ansIndex = nums.size() - 1; ansIndex > -1; ansIndex--)
	{
		if (std::abs(nums[low]) > std::abs(nums[high]))
		{
			ans[ansIndex] = nums[low] * nums[low];
			low++;
		}
		else
		{
			ans[ansIndex] = nums[high] * nums[high];
			high--;
		}
	}

	return ans;
}

// Copy, square and sort
// Time: O(n*log(n))
// Space: O(n)
vector<int> sortedSquares(vector<int> nums) // notice there is not & so this takes a copy of the received vector
{
	for (int &num : nums)
	{
		num *= num;
	}

	sort(nums.begin(), nums.end());

	return nums;
}