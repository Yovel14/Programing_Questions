int main()
{
	FastIO;

	int l, n;
	cin >> n >> l;
	double r = 0;
	double a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	r = max(a[0], l - a[n - 1]) * 2;
	for (int i = 1; i < n; i++)
		r = max(a[i] - a[i - 1], r);

	cout << fixed; // to not print in scientific notation
	cout << r / 2;

	return 0;
}