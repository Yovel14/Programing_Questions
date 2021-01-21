main()
{
	FastIO;

	// 4 verticale strip
	int a[5];
	for (int i = 1; i < 5; i++)
	{
		cin >> a[i];
	}
	int count = 0;
	string s;
	cin >> s;
	for (char &c : s)
	{
		count += a[c - '0'];
	}
	cout << count;

	return 0;
}