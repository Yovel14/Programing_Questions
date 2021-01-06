void inline solve()
{
	// Idea is to find the biggest of each negitive or positive sequence and add it to sum
	int n;
	cin >> n;

	long long sum = 0;

	int a, b; // a holds sequence max b holds current value
	cin >> a;
	n--;
	while (n--)
	{
		cin >> b;
		if ((a & (1 << 31)) == (b & (1 << 31))) // same sign
		{
			if (b > a)
				a = b;
		}
		else
		{
			sum += a;
			a = b;
		}
	}

	cout << sum + a << '\n';
}

int main()
{
	FastIO;

	int t;

	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}