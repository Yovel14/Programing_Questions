main() // this could be solved in o(1) with representing groth as a geometric sequence
{
	FastIO;

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}