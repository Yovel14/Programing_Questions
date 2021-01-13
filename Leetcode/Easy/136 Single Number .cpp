// time : O(n)
// space : O(1)
int singleNumber(vector<int> &nums)
{
	int single = 0;
	for (int &num : nums)
		single ^= num;
	return single;
}

// time : O(n)
// space : O(1)
int singleNumber(vector<int> &nums)
{
	unordered_set<int> s;
	int single = 0;
	for (int &num : nums)
	{
		if (s.find(num) != s.end())
			single -= num;
		else
		{
			single += num;
			s.insert(num);
		}
	}
	return single;
}

// time : O(n + n - 1) = O(n)
// space : O((n-1)/2 + 1) = O(n)
int singleNumber(vector<int> &nums)
{
	unordered_map<int, int> m;
	auto it = m.begin();

	for (int &num : nums)
	{
		it = m.find(num);
		if (it != m.end())
			it->second++;
		else
			m.insert({num, 1});
	}
	for (auto it2 : m)
		if (it2.second == 1)
			return it2.first;
	return -1;
}