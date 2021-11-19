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

ll po[41];
void inline preCampute()
{
	ll a = 1;
	for (int i = 0; i < 41; i++, a *= 3)
		po[i] = a;
}

void inline solve()
{
	ll n;
	cin >> n;

	int cnt = 0;
	ll tmp = n;
	while (tmp)
	{
		if (tmp & 1)
			cnt++;
		tmp >>= 1;
	}

	cout << cnt << '\n';

	int p = 0;
	while (n)
	{
		if (n & 1)
			cout << po[p] << ' ';
		p++;
		n >>= 1;
	}
	cout << '\n';
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