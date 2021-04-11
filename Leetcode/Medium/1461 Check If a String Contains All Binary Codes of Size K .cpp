// Time : O(n*k) where n is the length of str
// Space : O(2^k)
bool hasAllCodes(string str, int k)
{
	unordered_set<string> s;
	int n = str.size() - k + 1;
	for (int i = 0; i < n; i++)
		s.insert(str.substr(i, k));

	return s.size() == (1 << (k));
}

// Tine : O(n)
// Space : O(2^n)
// this algorithm works by using the fact that we are recinving string of the form of binary
// thus we can create an array of the size of all possible binary string and use the string as index
bool hasAllCodes(string str, int k)
{
	int n = str.size();
	if (k > n)
		return false;
	int count = (1 << k);
	int index = 0;
	bool exist[count + 1];
	memset(exist, 0, sizeof(exist));
	for (int i = n - 1, j = 0; i > (n - k); i--, j++) // build base for index
		index |= ((str[i] == '1') << j);

	for (int i = (n - k); i >= 0 && count; i--)
	{
		index |= ((str[i] == '1') << (k - 1));
		if (!exist[index])
		{
			count--;
			exist[index] = true;
		}

		index >>= 1;
	}

	return count == 0;
}