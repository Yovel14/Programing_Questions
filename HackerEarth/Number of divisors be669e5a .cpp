// mid utilization of the idea
#include <iostream>
#include <vector>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
using ll = long long;
using namespace std;

const int MOD = 1000000007;

void inline preCampute()
{
}

void inline solve()
{
	int n, k;
	cin >> n >> k;
	ll sum = (ll)(n) * (n + 1) / 2;
	for (int i = k, j = 1; i <= n; i += k, j++)
	{
		sum -= i;
		int tmp = j;
		while (tmp % k == 0)
			tmp /= k;
		sum += tmp;
	}
	cout << sum << '\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	//cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}

// full utilization
#include <iostream>
#include <vector>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
using ll = long long;
using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

void inline solve()
{
	ll n, k;
	cin >> n >> k;
	ll sum = 0;
	while (n)
	{
		int km = n / k; //amountOfMultiplesOfK
		sum += n * (n + 1) / 2 - 1ll * km * (km + 1) / 2 * k;
		n /= k;
	}
	cout << sum << '\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	//cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}