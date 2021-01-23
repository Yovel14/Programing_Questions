main()
{
	FastIO;

	int y, w;
	cin >> y >> w;
	int numerator = 6 - max(y, w) + 1;
	int denominator = 6;
	for (int num : {2, 3, 6})
	{
		if (numerator % num == 0 && denominator % num == 0)
		{
			numerator /= num;
			denominator /= num;
		}
	}
	cout << numerator << '/' << denominator;

	return 0;
}