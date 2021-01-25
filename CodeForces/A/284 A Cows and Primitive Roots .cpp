main()
{
	FastIO;

	int p;
	cin >> p;
	int count = 0;
	int mul;
	int j;
	for (int i = 1; i < p; i++)
	{
		mul = 1;
		for (j = 1; j < p; j++)
		{
			mul = (mul * i) % p;
			if ((mul - 1) == 0)
				break;
		}
		if (j == p - 1)
			count++;
	}

	cout << count;

	return 0;
}