#include <iostream>
#include <vector>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
#define vi vector<int>

using ll = long long;
using namespace std;

const int MOD = 1000000007;

void inline preCampute()
{
}

void inline solve()
{
	int n, c01, c10;
	cin >> n >> c01 >> c10;

	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll costZeroFirst = 0;
	bool one = false;
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		if (one != a[i])
		{
			if (one)
				costZeroFirst += c01;
			else
				costZeroFirst += c10;
		}
		one = !one;
	}

	ll costOneFirst = 0;
	one = true;
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		if (one != a[i])
		{
			if (one)
				costOneFirst += c01;
			else
				costOneFirst += c10;
		}
		one = !one;
	}

	cout << min(costOneFirst, costZeroFirst) << '\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}