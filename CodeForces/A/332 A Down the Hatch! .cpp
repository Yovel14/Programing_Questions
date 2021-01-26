main()
{
	FastIO;

	int n;
	string s;
	cin >> n;
	cin >> s;

	int m = s.size();
	int count = 0;
	for (int i = n; i < m; i += n)
	{
		if (s[i - 1] == s[i - 2] && s[i - 3] == s[i - 1])
			count++;
	}
	cout << count;

	return 0;
}