// Time : O(n)
// Space : O(1)
string minRemoveToMakeValid(string s)
{
	stack<int> st;
	int n = s.size();
	char c;

	for (int i = 0; i < n; i++)
	{
		c = s[i];
		if (c == '(')
			st.push(i);
		else if (c == ')')
		{
			if (st.empty())
				s[i] = '0';
			else
				st.pop();
		}
	}

	while (!st.empty())
	{
		s[st.top()] = '0';
		st.pop();
	}

	string ans = "";
	for (char &k : s)
		if (k != '0')
			ans.push_back(k);

	return ans;
}

// Time : O(n)
// Space : O(1)
string minRemoveToMakeValid(string s)
{
	int count = 0;
	for (char &c : s)
	{
		if (c == '(')
			count++;
		else if (c == ')')
		{
			if (count == 0)
				c = '0';
			else
				count--;
		}
	}

	count = 0;
	for (int i = s.size() - 1; i != -1; i--)
	{
		if (s[i] == ')')
			count++;
		else if (s[i] == '(')
		{
			if (count == 0)
				s[i] = '0';
			else
				count--;
		}
	}

	string ans = "";
	for (char &k : s)
		if (k != '0')
			ans.push_back(k);
	return ans;
}