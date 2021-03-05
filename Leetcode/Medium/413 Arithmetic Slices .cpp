// Time : O(n^2)
// Space : O(1)
int numberOfArithmeticSlices(vector<int> &nums)
{
	int n = nums.size();
	int count = 0;
	int dif;
	for (int i = 0; i + 2 < n; i++)
	{
		dif = nums[i + 1] - nums[i];
		for (int j = i + 1; j + 1 < n; j++)
		{
			if (nums[j + 1] - nums[j] != dif)
				break;
			count++;
		}
	}
	return count;
}

// Time : O(n)
// Space : O(1)
int numberOfArithmeticSlices(vector<int> nums)
{
	// how many sub array's are in [1,2,3,4]? 3 to caclutae do n(n+1)/2
	// number of sub array of length 1 2 are counted in the formula so
	// take out number of sub array 1 ,2  which is n + n-1
	// end formula is n*(n+1)/2 - (n + n-1) = n(n-3)/2+1;
	if (nums.size() < 3)
		return 0;
	int Total_count = 0;
	int count = 2;
	int n = nums.size() - 1;
	for (int i = 1; i < n; i++)
	{
		if (nums[i + 1] - nums[i] != nums[i] - nums[i - 1])
		{
			if (count == 3)
				Total_count++;
			else if (count > 3)
				Total_count += (count * (count - 3) / 2 + 1);
			count = 2;
		}
		else
			count++;
	}
	if (count == 3)
		Total_count++;
	else if (count > 3)
		Total_count += (count * (count - 3) / 2 + 1);
	return Total_count;
}

// Time : O(n)
// Space : O(n)
// checking for arithmetic sequences of 3 and trying to add at the begining of the sequence 1 more value each time
int slices(vector<int> &nums, int i, int &sum)
{
	if (i < 2)
		return 0;
	int ap = 0;
	if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
	{
		ap = 1 + slices(nums, i - 1, sum);
		sum += ap;
	}
	else
		slices(nums, i - 1, sum);
	return ap;
}
int numberOfArithmeticSlices(vector<int> &nums)
{
	int sum = 0;
	slices(nums, nums.size() - 1, sum);
	return sum;
}

// dp
// Time : O(n)
// Space : O(n)
int numberOfArithmeticSlices(vector<int> &nums)
{
	int sum = 0;
	int n = nums.size();
	int dp[n];
	memset(dp, 0, sizeof(dp));

	for (int i = 2; i < n; i++)
	{
		if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
		{
			dp[i] = dp[i - 1] + 1;
			sum += dp[i];
		}
	}
	return sum;
}

// improved dp
// Time : O(n)
// Space : O(1)
int numberOfArithmeticSlices(vector<int> &nums)
{
	int sum = 0;
	int n = nums.size();
	int prev = 0;

	for (int i = 2; i < n; i++)
	{
		if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
			sum += (++prev);
		else
			prev = 0;
	}
	return sum;
}