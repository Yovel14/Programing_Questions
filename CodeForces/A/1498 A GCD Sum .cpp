#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

// this question could be brute forced
// but the answer must be one of n, n+1, n+2
// because when a number is devisable by 3 sum of it's digets is devisibel by 3 thus at least one of these consecutive number must have a gcdSum>1

ll GCD(ll A, ll B)
{
	if (B == 0)
		return A;
	else
		return GCD(B, A % B);
}
int sumDigits(long long n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
void solve()
{
	ll n;
	cin >> n;

	if (GCD(n, sumDigits(n)) > 1)
		cout << n << '\n';
	else if (GCD(n + 1, sumDigits(n + 1)) > 1)
		cout << (n + 1) << '\n';
	else if (GCD(n + 2, sumDigits(n + 2)) > 1)
		cout << (n + 2) << '\n';
}

main()
{
	FastIO;

	int ctc;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}