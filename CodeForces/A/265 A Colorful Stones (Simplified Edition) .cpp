main()
{
	FastIO;

	string a, b;
	cin >> a >> b;
	int i = 0;
	for (char &c : b)
	{
		if (a[i] == c)
			i++;
	}
	cout << i + 1;

	return 0;
}