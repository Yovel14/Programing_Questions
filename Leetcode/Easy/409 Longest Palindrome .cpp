int longestPalindrome(string s) // it will be faster using an array
{
	// max of odd and sum of even is the max length
	unordered_map<char, int> count; // for faster O(1) time use array as in the function below
	auto amount = count.begin();
	for (char &c : s)
	{
		amount = count.find(c);
		if (amount != count.end())
			amount->second += 1;
		else
			count.insert({c, 1});
	}

	int odd_count = 0;
	int sum = 0;
	for (auto it = count.begin(); it != count.end(); ++it)
	{
		if (it->second & 1)
			odd_count++;
		sum += it->second;
	}

	if (odd_count > 0)
		return sum - (odd_count - 1);
	return sum;
}

int longestPalindrome(string s)
{
	int count[128] = {0};
	for (char &c : s)
		count[c]++;

	int odd_count = 0;
	int sum = 0;
	for (int &it : count)
	{
		if (it & 1)
			odd_count++;
		sum += it;
	}

	if (odd_count > 0)
		return sum - (odd_count - 1);
	return sum;
}