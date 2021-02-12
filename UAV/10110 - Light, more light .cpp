main()
{
	FastIO;

	// how does the number have an even or odd number of devisors (if a number is has a square root it has odd overwise even)
	long long n;
	double tmp;
	while ((cin >> n) && n)
	{
		tmp = sqrt(n);
		if (tmp == floor(tmp)) // has sqaure root
			cout << "yes\n";
		else
			cout << "no\n";
	}
}