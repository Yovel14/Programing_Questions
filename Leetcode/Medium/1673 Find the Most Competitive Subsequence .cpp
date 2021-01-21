// Time : O(n)
// Space : O(k)
vector<int> mostCompetitive(vector<int> &nums, int k)
{
	if (k == nums.size())
		return nums;
	int n = nums.size();
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		while (ans.size() && nums[i] < ans.back() && ans.size() + n - i > k)
			ans.pop_back();
		if (ans.size() < k)
			ans.push_back(nums[i]);
	}
	return ans;
}