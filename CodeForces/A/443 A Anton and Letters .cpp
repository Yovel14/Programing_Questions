main()
{
	FastIO;

	bool a[288] = {0};
	string s;
	getline(cin, s);
	int count = 0;
	int n = s.size();
	for (int i = 1; s[i] != '}' && i < n; i += 3)
	{
		if (!a[s[i]])
		{
			a[s[i]] = true;
			count++;
		}
	}
	cout << count;

	return 0;
}