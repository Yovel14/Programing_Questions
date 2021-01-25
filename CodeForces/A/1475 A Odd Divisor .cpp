main()
{
	FastIO;

	int t;
	long long n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n & (n - 1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}