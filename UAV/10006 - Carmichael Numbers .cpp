bool prime[65000] = {}; // false for prime
void seive()
{
	prime[0] = prime[1] = true;
	for (int i = 4; i < 65000; i += 2)
		prime[i] = true;

	for (int i = 3; i < 65000; i += 2)
		if (!prime[i])
			for (int j = (i << 1); j < 65000; j += i)
				prime[j] = true;
}

long long pw(long long a, int b, const int &m)
{
	if (b == 0)
		return 1;
	long long ans = 1;
	while (b && ans && a)
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

bool car(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (pw(i, n, n) != i)
			return false;
	}
	return true;
}

main()
{
	FastIO;

	seive();

	int n;
	while (cin >> n && n)
	{
		if (prime[n] && car(n))
			cout << "The number " << n << " is a Carmichael number.\n";
		else
			cout << n << " is normal.\n";
	}
}