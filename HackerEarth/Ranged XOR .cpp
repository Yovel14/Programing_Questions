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

int n;
int *a;

void inline preCampute()
{
	cin >> n;
	a = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}

void inline solve()
{
	int l, r;
	cin >> l >> r;
	int x = 0;
	int count0 = 0;
	for (; l <= r; l++)
	{
		x ^= a[l];
		if (a[l] == 0)
			count0++;
	}
	cout << x << ' ' << count0 << '\n';
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