int main()
{
	FastIO;

	long long n, max_grade, avg;
	cin >> n >> max_grade >> avg;

	long long sum = 0;
	long long get_to = n * avg;

	pair<long long, long long> a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
		sum += a[i].second;
	}
	sort(a, a + n);

	long long ans = 0;
	int i = 0;
	while (sum < get_to && i < n)
	{
		int temp = min(get_to - sum, max_grade - a[i].second);
		ans += temp * a[i].first;
		sum += temp;
		i++;
	}
	cout << ans;

	return 0;
}