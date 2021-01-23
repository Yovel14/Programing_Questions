// Time : O(n + m)
// Space : O(n+m)
bool closeStrings(string word1, string word2)
{
	if (word1.size() != word2.size())
		return false;
	unordered_map<char, int> w1_m, w2_m;
	unordered_map<int, int> w1_f, w2_f;
	set<char> w1_s, w2_s;
	unordered_map<int, int>::iterator f;
	unordered_map<char, int>::iterator it1;

	for (char &c : word1)
	{
		it1 = w1_m.find(c);
		if (it1 != w1_m.end())
			it1->second++;
		else
			w1_m[c] = 1;
		w1_s.insert(c);
	}

	for (char &c : word2)
	{
		it1 = w2_m.find(c);
		if (it1 != w2_m.end())
			it1->second++;
		else
			w2_m[c] = 1;
		w2_s.insert(c);
	}

	if (w1_s != w2_s)
		return false;

	for (auto it : w1_m)
	{
		f = w1_f.find(it.second);
		if (f != w1_f.end())
			f->second++;
		else
			w1_f[it.second] = 1;
	}

	for (auto it : w2_m)
	{
		f = w2_f.find(it.second);
		if (f != w2_f.end())
			f->second++;
		else
			w2_f[it.second] = 1;
	}

	for (auto it : w1_f)
	{
		f = w2_f.find(it.first);
		if (f == w2_f.end() || f->second != it.second)
			return false;
	}

	return true;
}
// improved by using array instead of hash set
// Time : O(n+m)
// Space : O(1)
bool closeStrings(string word1, string word2)
{
	if (word1.size() != word2.size())
		return false;
	int a1[288] = {0};
	int a2[288] = {0};
	for (char &c : word1)
		a1[c]++;
	for (char &c : word2)
		a2[c]++;
	for (int i = 0; i < 288; i++)
		if ((a1[i] == 0) != (a2[i] == 0))
			return false;
	sort(a1, a1 + 288);
	sort(a2, a2 + 288);
	for (int i = 287; i >= 0; i--)
	{
		if (a1[i] != a2[i])
			return false;
		if (a1[i] == 0)
			return true;
	}
	return true;
}

// improved space // but for larger strings this would be a bit slower
// Time : O(n+m)
// Space : O(1)
bool closeStrings(string word1, string word2)
{
	if (word1.size() != word2.size())
		return false;
	int a1[26] = {0};
	int a2[26] = {0};
	for (char &c : word1)
		a1[c - 'a']++;
	for (char &c : word2)
		a2[c - 'a']++;
	for (int i = 0; i < 26; i++)
		if ((a1[i] == 0) != (a2[i] == 0))
			return false;
	sort(a1, a1 + 26);
	sort(a2, a2 + 26);
	for (int i = 25; i >= 0; i--)
	{
		if (a1[i] != a2[i])
			return false;
		if (a1[i] == 0)
			return true;
	}
	return true;
}