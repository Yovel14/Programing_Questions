// Time : O(n)
// Space : O(1)
int resolve(char c)
{
	if (c == 'I')
		return 1;
	if (c == 'V')
		return 5;
	if (c == 'X')
		return 10;
	if (c == 'L')
		return 50;
	if (c == 'C')
		return 100;
	if (c == 'D')
		return 500;
	if (c == 'M')
		return 1000;
	return 0;
}

int romanToInt(string s)
{
	// Idea:
	// go from the end and check if current is smaller than the last if it is than it means need to subtruct the current value
	//I know that because the number is of the form the larger number at the start
	int cur;
	int last = -1;
	int sum = 0;

	for (int i = s.size() - 1; i >= 0; --i)
	{
		cur = resolve(s[i]);
		if (cur < last)
			sum -= cur;
		else
			sum += cur;
		last = cur;
	}

	return sum;
}