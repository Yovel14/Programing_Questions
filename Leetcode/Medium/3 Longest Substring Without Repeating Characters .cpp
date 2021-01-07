int lengthOfLongestSubstring(string &s) // O(2*n)
{
	// I will do this with two pointers one for start and one for end and use a map to check whay is in the current string
	int start = 0;
	int end = 0;
	int mx_length = 0;
	bool exist[189] = {0};
	int n = s.size();

	while (end < n)
	{
		if (!exist[s[end]])
		{
			exist[s[end]] = true;
			mx_length = max(mx_length, end - start + 1);
			end++;
		}
		else
		{
			exist[s[start]] = false;
			start++;
		}
	}

	return mx_length;
}

int lengthOfLongestSubstring(string &s) // O(n)
{
	// since the string consists only of ascii char I can use an array
	int exist[128];
	memset(exist, -1, sizeof(exist));
	int mx_length = 0;
	int start = 0;
	int end = 0;
	int n = s.size();

	while (end < n)
	{
		if (exist[s[end]] < start)
		{
			exist[s[end]] = end;
			mx_length = max(mx_length, end - start + 1);
			end++;
		}
		else
			start = exist[s[end]] + 1;
	}

	return mx_length;
}

// all of the above solutions can be done with a map but since there are only ascii chars there is no need to use map because o(1) of an array is faster than of that on a unordered map