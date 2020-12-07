int lengthOfLongestSubstring(string s) // O(n) solution sliding window
{
	// use map to detirmin repeating char and do a sliding window
	unordered_set<char> exist;
	int mx = 0;
	int i = 0;
	int j = 0;
	int len = s.size();
	while (i < len && j < len)
	{
		if (exist.find(s[j]) == exist.end())
		{
			exist.insert(s[j]);
			++j;
		}
		else
		{
			if (j - i > mx)
				mx = j - i;
			exist.erase(s[i]);
			++i;
		}
	}
	if (j - i > mx)
		return j - i;
	return mx;
}

int lengthOfLongestSubstring(string s)
{
	// optimized sliding window
	unordered_map<char, int> exist;
	int mx = 0;
	int i = 0;
	int j = 0;
	int len = s.size();
	while (i < len && j < len)
	{
		if (exist.find(s[j]) != exist.end())
			i = max(exist[s[j]], i);

		if (j - i + 1 > mx)
			mx = j - i + 1;

		exist[s[j]] = j + 1;
		++j;
	}

	return mx;
}

int lengthOfLongestSubstring(string s)
{
	// since the string consists only of ascii char I can use an array and each index will be a ascii number for that char
	int exist[128] = {0};
	int mx = 0;
	int i = 0;
	int j = 0;
	int len = s.size();
	while (i < len && j < len)
	{
		if (exist[s[j]] != 0)
			i = max(exist[s[j]], i);

		if (j - i + 1 > mx)
			mx = j - i + 1;

		exist[s[j]] = j + 1;
		++j;
	}

	return mx;
}