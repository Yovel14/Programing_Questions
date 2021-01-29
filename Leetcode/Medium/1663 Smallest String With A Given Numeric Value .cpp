string getSmallestString(int n, int k)
{
	string s(n, 'a');
	k -= n;

	for (int i = n - 1; i >= 0 && k > 0; i--)
	{
		s[i] += min(k, 25);
		k -= 25;
	}
	return s;
}