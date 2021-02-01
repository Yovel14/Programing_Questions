int rev_bin(int a)
{
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		ans <<= 1;
		ans |= 1 & a;
		a >>= 1;
	}
	return ans;
}
main()
{
	FastIO;

	string s;
	getline(cin, s);
	s = char(0) + s;

	int n = s.size();
	for (int i = 1; i < n; i++)
	{
		s[i] = rev_bin(s[i]);
		cout << ((s[i - 1] - s[i]) % 256 + 256) % 256 << '\n';
	}

	return 0;
}