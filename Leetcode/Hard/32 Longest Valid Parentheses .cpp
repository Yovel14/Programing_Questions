// TLE
// Time : O(n^3)
// Space : O(n^2) because going n time into isValid and it has a stack
bool isValid(string &s, int start, int end)
{
	stack<char> cs;
	char c;

	for (; start <= end; start++)
	{
		c = s[start];
		if (c == '(' || c == '[' || c == '{')
		{
			cs.push(c);
		}
		else
		{
			if (cs.empty() || (c == ')' && cs.top() != '(') || (c == ']' && cs.top() != '[') || (c == '}' && cs.top() != '{'))
				return false;
			cs.pop();
		}
	}
	return cs.empty();
}
int longestValidParentheses(string s) // the function below this with the same name improves the brute force by a bit
{
	int n = s.size();
	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (isValid(s, i, j))
				mx = max(mx, j - i);
	return mx == 0 ? 0 : mx + 1;
}

// improvment but still TLE
int longestValidParentheses(string s)
{
	/*
	all the improvements are on the innner loop
	1. I started the loop from as close to the end as possible thus I can exit the innner loop because that will be the biggest I will find starting fron i
	2. I am making sure I only check even lengths by starting j as n-1 if the maximum possible length even otherwise I start from n-2 and I skip by 2 each time to reserve even lengths
	*/
	int n = s.size();
	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = (n - i) & 1 ? n - 2 : n - 1; j != i && mx < (j - i + 1); j -= 2)
			/
				if (isValid(s, i, j))
			{
				mx = max(mx, j - i);
				break;
			}
	return mx == 0 ? 0 : mx + 1;
}

// dp
// Time : O(n)
// Space : O(n)
int longestValidParentheses(string s)
{
	int n = s.size();
	int *dp = new int[n]();
	int mx = 0;
	if (n > 1)
		if (s[0] == '(' && s[1] == ')')
		{
			dp[1] = 2;
			mx = 2;
		}

	for (int i = 2; i < n; i++)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(')
				dp[i] = dp[i - 2] + 2;
			else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
				dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
			mx = max(mx, dp[i]);
		}
	}
	return mx;
}

// stack
// Time : O(n)
// Space : O(n)
int longestValidParentheses(string s)
{
	stack<int> st;
	st.push(-1);
	int n = s.size();
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			st.push(i);
		else
		{
			st.pop();
			if (st.empty())
				st.push(i);
			else
				mx = max(mx, i - st.top());
		}
	}
	return mx;
}

// no extra space
// Time : O(n)
// Space : O(1)
int longestValidParentheses(string s)
{
	int mx = 0;
	int open = 0;
	int closed = 0;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			open++;
		else if (open == (++closed))
			mx = max(mx, open);
		else if (closed > open)
			open = closed = 0;
	}

	open = closed = 0;
	for (int i = n - 1; i != -1; i--)
	{
		if (s[i] == ')')
			open++;
		else if (open == ++closed)
			mx = max(mx, open);
		else if (closed > open)
			open = closed = 0;
	}
	return (mx << 1);
}