// time : O(n)
// space : O(1)
vector<int> singleNumber(vector<int> &nums)
{
	/*
        first get the two single number in two veriable
        second find the first 1 bit because since we xor it will be on at the first and not the second or vice versa
        and xor all the numbers that have that bit on to get one of the numbers out of the veriable two
        */

	int two = 0; // two will hold the two single numbers
	for (int &n : nums)
		two ^= n;

	int first_bit;
	if (two > -2147483648 && two < 2147483647)
		first_bit = two & (~two + 1);
	else
		first_bit = 1;

	int single = two; // single will find one of the numbers

	for (int &n : nums)
		if (first_bit & n)
			single ^= n;

	return {single, two ^ single};
}

// time : O(nlog(n))
// space : O(1)
vector<int> singleNumber(vector<int> &nums)
{
	int first = 0;
	bool found = false;
	int n = nums.size() - 1;

	sort(nums.begin(), nums.end());

	int i = 0;
	while (i < n)
	{
		if (nums[i] != nums[i + 1])
		{
			if (found)
				return {first, nums[i]};
			first = nums[i];
			found = true;
			i++;
		}
		else
			i += 2;
	}

	return {first, nums[n]};
}

// time : O(n)
// space : O((n-2)/2 + 2) = O(n)
vector<int> singleNumber(vector<int> &nums)
{
	unordered_map<int, int> m;
	auto it = m.begin();
	bool first = false;
	int f;

	for (int &n : nums)
	{
		it = m.find(n);
		if (it != m.end())
			it->second++;
		else
			m.insert({n, 1});
	}

	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second == 1)
		{
			if (first)
				return {f, it->first};
			first = true;
			f = it->first;
		}
	}
	return {-1, -1}; // will never get here because of question description
}