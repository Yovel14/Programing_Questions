main()
{
	FastIO;

	// n ,b,d
	// n number of oranges
	// b maximum size;
	// d when the wast should be empty

	int n, b, d;
	cin >> n >> b >> d;

	int a;
	int sum = 0;
	int count = 0;
	while (n--)
	{
		cin >> a;
		if (a > b)
			continue;

		sum += a;
		if (sum > d)
		{
			count++;
			sum = 0;
		}
	}
	cout << count;

	return 0;
}