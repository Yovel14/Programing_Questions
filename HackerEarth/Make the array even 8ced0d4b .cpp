#include <iostream>
#include <vector>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void inline solve()
{
	// p = a[i] + a[i+1]
	// q = a[i]-a[i+1]
	// a[i] = p, a[i+1] = q;
	// if a[i] == a[i+1] than they will be even // add 1 if a[i] or a[i+1] are odd
	// if a[i] and a[i+1] are odd than a[i] and a[i+1] are now even// add 1
	// if one is odd than make both odd then make both even // add 2

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;

	if (a[n - 1] & 1)
	{
		if (a[n - 2] & 1)
			ans++;
		else
			ans += 2;
		a[n - 1] = 0;
		a[n - 2] = 0;
	}

	for (int i = 0; i + 1 < n; i++)
	{
		if (a[i] & 1 ^ 1) // if even
			continue;

		a[i] = 0;

		if (a[i + 1] & 1)
		{
			ans++;
			a[i + 1] = 0;
		}
		else
			ans += 2;
	}

	cout << ans << '\n';
}

main()
{
	FastIO;

	int ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}