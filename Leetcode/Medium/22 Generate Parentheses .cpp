// solution 1
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

// solution 2
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