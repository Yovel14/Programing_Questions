// solution 1
vector<string> generateParenthesis(int n)
{
	if (n == 0)
		return {""};
	vector<vector<string>> cache(n + 1);
	cache[0] = {""};

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < i; ++j)
		{
			vector<string> left = cache[j];
			vector<string> right = cache[i - j - 1];
			for (string &l : left)
				for (string &r : right)
					cache[i].push_back("(" + l + ")" + r);
		}
	return cache[n];
}

// solution 2
void solve(int &n, int count_open, int count_closed, string current, vector<string> &com)
{
	if (count_open == n && count_closed == n)
		com.push_back(current);
	else
	{
		if (count_open < n)
			solve(n, count_open + 1, count_closed, current + '(', com);
		if (count_closed < count_open)
			solve(n, count_open, count_closed + 1, current + ')', com);
	}
}

vector<string> generateParenthesis(int &n)
{
	vector<string> com;
	solve(n, 0, 0, "", com);
	return com;
}

// solution 3
vector<string> generateParenthesis(int n) // there might be a possibility to use memozation to reduce time complexity in this solution
{
	if (n == 0)
		return {""};

	vector<string> ans;
	for (int c = 0; c < n; c++)
		for (string left : generateParenthesis(c))
			for (string right : generateParenthesis(n - 1 - c))
				ans.push_back("(" + left + ")" + right);
	return ans;
}