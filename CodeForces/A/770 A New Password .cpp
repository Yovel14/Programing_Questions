main()
{
	FastIO;

	// length n
	// only lower case latin
	// number of distinct should equal k
	// any two consicitive sould be distinct

	int n, k;
	cin >> n >> k;
	string s = "";
	char rol = 'a';
	int back = 1;
	while (n)
	{
		rol = 'a';
		for (int i = 0; i < k && n; i++)
		{
			s += rol;
			n--;
			rol++;
		}
	}
	cout << s;

	return 0;
}