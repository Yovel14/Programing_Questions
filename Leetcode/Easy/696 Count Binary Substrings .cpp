// Time : O(n)
// Space : O(1)
int countBinarySubstrings(string s)
{
	int count = 0;
	int n = s.size();
	int prev = 0;
	int cur = 1;

	int i = 0;
	while (i < n)
	{
		i++;
		while (s[i] == s[i - 1] && i < n)
		{
			cur++;
			i++;
		}
		count += min(cur, prev);
		prev = cur;
		cur = 1;
	}

	return count;
}

// Time : O(n^2)
// Space : O(1)
int countBinarySubstrings(string s)
{
	int count = 0;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		int parity = 0;
		int j = i;
		char startChar = s[j];
		while (j < n && s[j] == startChar)
		{
			j++;
			parity++;
		}

		startChar = startChar == '0' ? '1' : '0';
		while (j < n && parity && s[j] == startChar)
		{
			j++;
			parity--;
		}
		if (parity == 0)
			count++;
	}

	return count;
}