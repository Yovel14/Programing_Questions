main()
{
	FastIO;

	// start give x packs
	// find distressed and how much is left
	int n;
	long long x;
	cin >> n >> x;
	int a;
	char c;
	int count = 0;
	while (n--)
	{
		cin >> c;
		cin >> a;
		if (c == '+')
			x += a;
		else
		{
			if (a > x)
				count++;
			else
				x -= a;
		}
	}
	cout << x << ' ' << count;

	return 0;
}