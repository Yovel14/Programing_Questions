bool isValid(string s)
{
	stack<char> cs;

	for (char &c : s)
	{
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