main()
{
	FastIO;

	//t for oven to bake k cakes
	// need n
	// d minutes to build another oven
	// can bake cakees while building another oven

	int n, t, k, d;
	cin >> n >> t >> k >> d;

	int time = 0;
	while (time <= d)
	{
		n -= k;
		time += t;
	}
	if (n > 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}