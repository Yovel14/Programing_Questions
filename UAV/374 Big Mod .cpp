int pw(int a, int b, int m)
{
	if (a == 0 && b != 0)
		return 0;
	if (b == 0)
		return 1;
	if (a > m)
		a %= m;
	int ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans *= a;
			if (m <= ans)
				ans %= m;
		}
		b >>= 1;
		if (b)
		{
			a *= a;
			if (m <= a)
				a %= m;
		}
	}
	return ans;
}
main()
{
	FastIO;

	// R = b^p mod m
	int b, p, m;
	while (cin >> b)
	{
		cin >> p >> m;
		cout << pw(b, p, m) << '\n';
	}
}