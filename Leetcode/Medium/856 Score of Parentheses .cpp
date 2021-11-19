// Time : O(n)
// Space : O(n)
int solve(int &index, string &s)
{
	int sum = 0;
	while (index < s.size())
	{
		if (s[index++] == '(')
			sum += solve(index, s);
		else
			return sum ? (sum << 1) : 1;
	}
	return sum;
}
int scoreOfParentheses(string &s)
{
	int index = 0;
	return solve(index, s);
}

// Time : O(n^2)
// Space : O(n)
// find the begining and end of '(' ')' and double the sum of what is inside
int solve(string &str, int s, int e)
{
	int sum = 0;
	int bal = 0;
	for (int i = s; i < e; i++)
	{
		bal += (str[i] == '(' ? 1 : -1);
		if (bal == 0)
		{
			if (i - s == 1)
				sum++;
			else
				sum += 2 * solve(str, s + 1, i);
			s = i + 1;
		}
	}
	return sum;
}
int scoreOfParentheses(string &s)
{
	return solve(s, 0, s.size());
}

// Time : O(n)
// Space : O(1)
// reliese on the fact than (()()) == 2*(1+1) = 2*1 + 2*1
int scoreOfParentheses(string &s)
{
	int sum = 0, bal = 0;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			bal++;
		else
		{
			bal--;				 // before and not after to not count itself as a depth
			if (s[i - 1] == '(') // since s is balanced than i-1 will always be over 0
				sum += (1 << bal);
		}
	}
	return sum;
}

// Time : O(n)
// Space : O(n)
int scoreOfParentheses(string &s)
{
	stack<int> st;
	st.push(0);

	int a;
	for (char &c : s)
	{
		if (c == '(')
			st.push(0);
		else
		{
			a = st.top();
			st.pop();
			st.top() += (a ? (a << 1) : 1);
		}
	}
	return st.top(); // I know the stack will not empty because amount of '(' == ')' and at the begining I am adding to double
}