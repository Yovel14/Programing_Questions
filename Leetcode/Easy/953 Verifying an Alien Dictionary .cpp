// Time : O(l + n) where l is the sum of of lengths in words, n is the size of order
// Space : O(1)
bool isAlienSorted(vector<string> &words, string order)
{
	int o[27] = {};
	int n = order.size();
	for (int i = 0; i < n; i++)
		o[order[i] - 'a'] = i;

	int m = words.size();
	for (int i = 1; i < m; i++)
	{
		int j = 0, k = 0;
		for (; j < words[i - 1].size() && k < words[i].size() && words[i - 1][j] == words[i][k]; j++, k++)
		{
		}

		if (k == words[i].size() && j != words[i - 1].size())
			return false;
		if (j < words[i - 1].size() && k < words[i].size() && o[words[i - 1][j] - 'a'] > o[words[i][k] - 'a'])
			return false;
	}
	return true;
}