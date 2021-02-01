main()
{
	FastIO;

	int n;
	string s;
	cin >> n >> s;
	int i = 0;
	n--;
	for (; i < n; i++)
	{
		if (s[i] > s[i + 1])
			break;
	}
	if (i == n)
		cout << "NO";
	else
		cout << "YES\n"
			 << i + 1 << ' ' << i + 2;

	return 0;
}