main()
{
	FastIO;

	string s;
	cin >> s;
	int n = s.size();
	int asize = trunc(n / 2) + 1;
	char a[asize];
	int p = 0;

	for (int i = 0; i < n; i += 2)
		a[p++] = s[i];
	sort(a, a + asize);
	for (int i = 0; i < asize - 1; i++)
		cout << a[i] << '+';
	cout << a[asize - 1];

	return 0;
}