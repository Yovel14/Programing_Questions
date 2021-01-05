int main()
{
	FastIO;

	int g, b;

	cin >> g;
	int girls[g];
	for (int i = 0; i < g; i++)
		cin >> girls[i];

	cin >> b;
	int boys[b];
	for (int i = 0; i < b; i++)
		cin >> boys[i];

	sort(girls, girls + g);
	sort(boys, boys + b);

	int i = 0, j = 0;
	int count = 0;
	while (i < b && j < g)
	{
		if (abs(girls[j] - boys[i]) <= 1)
		{
			count++;
			j++;
			i++;
		}
		else
		{
			if (boys[i] < girls[j])
				i++;
			else
				j++;
		}
	}
	cout << count;

	return 0;
}