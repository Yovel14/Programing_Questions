main() // this could be solved in o(1) with representing groth as a geometric sequence
{
	FastIO;

	int ans = -1;
	int temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> temp;
			if (temp)
			{
				ans = abs(j - 2) + abs(i - 2);
			}
		}
	}
	cout << ans;

	return 0;
}