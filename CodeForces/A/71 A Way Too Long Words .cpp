main()
{
	FastIO;

	int t;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> s;
		if (s.size() > 10)
		{
			cout << s[0] << s.size() - 2 << s.back() << '\n';
		}
		else
			cout << s << '\n';
	}

	return 0;
}