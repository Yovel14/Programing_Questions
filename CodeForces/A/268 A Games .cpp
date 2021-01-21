main()
{
	FastIO;

	int n;
	cin >> n;

	int t;
	unordered_map<int, int> h;
	unordered_map<int, int> g;
	unordered_map<int, int>::iterator it;
	while (n--)
	{
		cin >> t;

		it = h.find(t);
		if (it != h.end())
			it->second++;
		else
			h[t] = 1;

		cin >> t;
		it = g.find(t);
		if (it != g.end())
			it->second++;
		else
			g[t] = 1;
	}

	int count = 0;
	unordered_map<int, int>::iterator it2;
	for (it = h.begin(); it != h.end(); it++)
	{
		it2 = g.find(it->first);
		if (it2 != g.end())
			count += (it->second) * it2->second;
	}
	cout << count;

	return 0;
}