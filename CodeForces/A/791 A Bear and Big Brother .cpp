main() // this could be solved in o(1) with representing groth as a geometric sequence
{
	FastIO;

	// limak a
	// bob b
	// a<b
	// limak triple bob double
	int a, b;
	cin >> a >> b;
	int count = 0;
	while (a <= b)
	{
		a *= 3;
		b *= 2;
		count++;
	}
	cout << count;

	return 0;
}