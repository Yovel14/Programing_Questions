main()
{
	FastIO;

	int n, h;
	cin >> n >> h;
	int temp;
	int count = n;
	while (n--)
	{
		cin >> temp;
		if (temp > h)
			count++;
	}
	cout << count;

	return 0;
}