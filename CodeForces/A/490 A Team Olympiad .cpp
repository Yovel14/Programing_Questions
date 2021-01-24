main()
{
	FastIO;

	// 1 programming
	// 2 math
	// 3 pe
	int n, t;
	cin >> n;
	vector<int> a1;
	vector<int> a2;
	vector<int> a3;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t == 1)
			a1.push_back(i + 1);
		else if (t == 2)
			a2.push_back(i + 1);
		else
			a3.push_back(i + 1);
	}
	int m = min(a1.size(), min(a2.size(), a3.size()));
	cout << m << '\n';

	int i = 0;
	while (m--)
		cout << a1[i] << ' ' << a2[i] << ' ' << a3[i++] << '\n';

	return 0;
}