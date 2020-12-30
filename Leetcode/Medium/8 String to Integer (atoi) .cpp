int myAtoi(string s)
{
	if (s.size() == 0)
		return 0;

	int n = s.size();
	int i = 0;

	while (i < n && (s[i] == ' '))
		i++;

	bool negitive = false;
	if (i < n && (s[i] == '-' || s[i] == '+'))
		negitive = (s[i++] == '-' ? true : false);

	int ans = 0;
	while (i < n && s[i] >= '0' && s[i] <= '9')
	{
		if (ans > 214748364 || (ans == 214748364 && s[i] - '0' > 7))
		{
			return (negitive ? INT_MIN : INT_MAX);
		}
		ans = ans * 10 + (s[i++] - '0');
	}
	return (negitive ? (~ans + 1) : ans);
}