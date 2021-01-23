main()
{
	FastIO;

	int a[4];
	for (int i = 0; i < 4; i++)
		cin >> a[i];

	int shoes = 0;
	int count;
	for (int i = 0; i < 4; i++)
	{
		count = 0;
		for (int j = i + 1; j < 4; j++)
			if (a[i] == a[j])
			{
				count++;
				break;
			}
		if (count == 0)
			shoes++;
	}
	cout << 4 - shoes;

	return 0;
}