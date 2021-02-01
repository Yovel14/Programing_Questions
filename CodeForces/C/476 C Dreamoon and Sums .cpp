main()
{
	FastIO;

	/*
* let d = x/b
* let m = x/b
* x = d*b + m;
* x = mk*b + m = m(kb+1)
* S[m = 1,b-1](m*(kb+1)) = (kb+1)*(b*b-1)/2
* S[k = 1, a]((kb+1)*(b*b-1)/2) = (a(a+1)/2 * b + a)*(b(b-1)/2)
*/

	long long a, b;
	cin >> a >> b;
	int mod = 1000000007;
	cout << (a * (a + 1) / 2 % mod * b % mod + a) * (b * (b - 1) / 2 % mod) % mod;

	return 0;
}