main()
{
	FastIO;

	int n;
	cin >> n;
	int count = 1;
	int cur;
	int prev;
	cin >> prev;
	n--;
	while (n--)
	{
		cin >> cur;
		if (cur != prev)
		{
			count++;
			prev = cur;
		}
	}
	cout << count;

	return 0;
}