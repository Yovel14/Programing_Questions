// Solution 1:
// check the possibility of existance for every possible sum
void all_sum(int n, bool a[])
{
	if (n < 1000001)
	{
		if (!a[n])
		{
			a[n] = true;
			all_sum(n + 2021, a);
			all_sum(n + 2020, a);
		}
	}
}

main()
{
	FastIO;

	int t, n;
	cin >> t;
	bool a[1000001] = {0};
	all_sum(0, a);

	while (t--)
	{
		cin >> n;
		if (a[n])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

// Solution 2:

/*

let a = count of 2020
let b = count of 2021

n = 2020*a + 2021*b;
n = 2020*a + 2020*b + b;
n = (a+b)*2020 + b;
n - b = (a+b)(2020);
a+b = (n - b)/ 2020;
a = (n - b)/2020 -b;

*/
main()
{
	FastIO;

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		int count2021 = n % 2020;
		int count2020 = (n - count2021) / 2020 - count2021;
		if (count2020 >= 0 && count2020 * 2020 + count2021 * 2021 == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}