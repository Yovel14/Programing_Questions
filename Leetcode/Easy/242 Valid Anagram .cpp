// Time : O(n)
// Space : O(1)
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;

	int count[27] = {0};
	int index;

	for (char &c : s)
		count[c - 'a']++;

	for (char &c : t)
	{
		index = c - 'a';
		count[index]--;
		if (count[index] < 0)
			return false;
	}

	for (int i = 0; i < 27; i++)
		if (count[i] != 0)
			return false;

	return true;
}

// Time : O(n) where n is the size of s and t
// Space : O(n)
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;

	unordered_multiset<char> ms;
	unordered_multiset<char>::iterator it;
	for (char &c : s)
		ms.insert(c);

	for (char &c : t)
	{
		it = ms.find(c);
		if (it == ms.end())
			return false;

		ms.erase(it);
	}

	return ms.size() == 0;
}

// Time : O(nlog(n))
// Space O(1)
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}