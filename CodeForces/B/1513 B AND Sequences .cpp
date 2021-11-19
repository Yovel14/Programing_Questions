#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
using ll = long long;
using namespace std;

void inline preCampute() {}

void inline solve()
{
	int n;
	cin >> n;
	v(int) a(n);
	int mn = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mn = min(mn, a[i]);
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == mn)
			count++;
		else if ((a[i] & mn) != mn)
		{
			cout << 0 << '\n';
			return;
		}
	}
	ll mod = 1000000007;
	ll ans(1LL * count * (count - 1) % mod);
	for (int i = n - 2; i > 0; i--)
		ans = (ans * i) % mod;

	cout << ans << '\n';
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