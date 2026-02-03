// where n is length of nums
// time : O(n)
// space : O(n)
bool containsDuplicate(vector<int> &nums)
{
	unordered_set<int> s;
	for (int &num : nums)
	{
		if (s.find(num) != s.end())
			return true;
		s.insert(num);
	}
	return false;
}



// where n is Length of nums
// time : O(nlog(n))
// space : O(1)
bool containsDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  for(int i = nums.size()-1; i>0; i--)
  {
      if(nums[i] == nums[i-1])
          return true;
  }

  return false;
}