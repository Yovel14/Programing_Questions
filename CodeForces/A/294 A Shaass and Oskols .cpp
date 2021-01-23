main()
{
	FastIO;

	// n horizontal wires in paralel

	int n, m, x, y;
	cin >> n;

	int a[++n + 1];
	for (int i = 1; i < n; i++)
		cin >> a[i];

	cin >> m;
	while (m--)
	{
		cin >> x >> y;
		a[x - 1] += (y - 1);
		a[x + 1] += (a[x] - y);
		a[x] = 0;
	}
	for (int i = 1; i < n; i++)
		cout << a[i] << '\n';

	return 0;
}