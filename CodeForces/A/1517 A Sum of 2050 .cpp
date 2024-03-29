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

// Special types
template <typename T>
using vc = std::vector<T>;
template <class T>
using vc = std::vector<T>;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using ll = long long;

using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

void inline solve()
{
	long long n;
	cin >> n;
	if (n % 2050 != 0)
	{
		cout << -1 << '\n';
		return;
	}

	n /= 2050;
	int ans = 0;
	while (n)
	{
		ans += n % 10;
		n /= 10;
	}
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