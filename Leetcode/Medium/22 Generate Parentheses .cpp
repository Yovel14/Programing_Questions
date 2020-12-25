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