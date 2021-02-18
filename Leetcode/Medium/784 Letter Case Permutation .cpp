// Time : O(2^n) where n is the number of alphbetic letters
// Space : O(2^n)
void solve(string &s, vector<string> &ans, int index)
{
	if (index == s.size())
	{
		ans.push_back(s);
		cout << s << ' ';
		return;
	}

	solve(s, ans, index + 1);
	if (s[index] >= 'a' && s[index] <= 'z')
	{
		s[index] -= 32;
		solve(s, ans, index + 1);
		s[index] += 32;
	}
}
vector<string> letterCasePermutation(string s)
{
	vector<string> ans;
	for (char &c : s)
		if (c >= 'A' && c <= 'Z')
			c += 32;
	solve(s, ans, 0);
	return ans;
}

// improved the depth of recursion
// Time : O(2^n) where n is the number of alphbetic letters
// Space : O(2^n)
void solve(string &s, vector<string> &ans, int index)
{
	if (index == s.size())
	{
		ans.push_back(s);
		cout << s << ' ';
		return;
	}

	while (index < s.size() && s[index] < 'a' || s[index] > 'z') // to lower the recursion depth
		index++;
	if (index == s.size())
	{
		ans.push_back(s);
		return;
	}

	solve(s, ans, index + 1);
	if (s[index] >= 'a' && s[index] <= 'z')
	{
		s[index] -= 32;
		solve(s, ans, index + 1);
		s[index] += 32;
	}
}
vector<string> letterCasePermutation(string s)
{
	vector<string> ans;
	for (char &c : s) // just to simplify the question but it could be done without changeing to lower
		if (c >= 'A' && c <= 'Z')
			c += 32; // change to lower case
	solve(s, ans, 0);
	return ans;
}

// without lowering the input string char
// Time : O(2^n) where n is the number of alphbetic letters
// Space : O(2^n)
void solve(string &s, vector<string> &ans, int index)
{
	if (index == s.size())
	{
		ans.push_back(s);
		cout << s << ' ';
		return;
	}

	while (index < s.size() && !((s[index] >= 'a' && s[index] <= 'z') || (s[index] >= 'A' && s[index] <= 'Z'))) // to lower the recursion depth
		index++;
	if (index == s.size())
	{
		ans.push_back(s);
		return;
	}

	solve(s, ans, index + 1);
	if (s[index] >= 'a' && s[index] <= 'z')
	{
		s[index] -= 32;
		solve(s, ans, index + 1);
		s[index] += 32;
	}
	else
	{
		s[index] += 32;
		solve(s, ans, index + 1);
		s[index] -= 32;
	}
}
vector<string> letterCasePermutation(string s)
{
	vector<string> ans;
	solve(s, ans, 0);
	return ans;
}