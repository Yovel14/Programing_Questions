main()
{
	FastIO;

	int k, r;
	cin >> k >> r;
	int count = 1;
	int reminder;
	while (count < 10)
	{
		reminder = (k * count) % 10;
		if (reminder == 0 || reminder == r)
			break;
		count++;
	}
	cout << count;

	return 0;
}