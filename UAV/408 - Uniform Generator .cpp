int inline next_seed(int step, int mod, int prev)
{
	return (prev + step) % mod;
}

main()
{
	FastIO;

	//seed(x+1) = (seed(x) + step)%mod
	// good id for step and mod who generate all numbers between 0 and mod-1// this is mod amount of numbers;
	int s, m;
	unordered_set<int> se; // could be made faster with using an array
	while (cin >> s >> m)
	{
		se = {};
		for (int x = 0;; x = next_seed(s, m, x))
		{
			if (se.find(x) != se.end())
				break;
			se.insert(x);
		}
		cout << setw(10) << s << setw(10) << m << "    ";
		se.size() == m ? cout << "Good Choice\n\n" : cout << "Bad Choice\n\n";
	}

	return 0;
}