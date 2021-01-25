main()
{
	FastIO;

	int p, n;
	cin >> p >> n;
	int t;
	int conflict = -1;
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		t = t % p;
		if (conflict == -1 && s.find(t) != s.end())
		{
			conflict = i;
		}
		else
			s.insert(t);
	}
	cout << conflict + (conflict != -1 ? 1 : 0);

	return 0;
}