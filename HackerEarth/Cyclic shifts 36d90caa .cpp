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

const int MOD = 1000000007;

void inline preCampute() {}

void inline solve()
{
	int n, m;
	char c;
	cin >> n >> m >> c;
	if (c == 'L')
	{
		while (m--)
		{
			if ((n >> 15) & 1)
			{
				n ^= (1 << 15);
				n <<= 1;
				n |= 1;
			}
			else
				n <<= 1;
		}
	}
	else
	{
		while (m--)
		{
			if (n & 1)
			{
				n >>= 1;
				n |= (1 << 15);
			}
			else
				n >>= 1;
		}
	}
	cout << n << '\n';
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