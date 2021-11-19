#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

int sum[10000001];
int ans[10000001];

void inline preCampute()
{
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i < 10000001; i++)
	{
		ans[i] = -1;
		for (int j = i; j < 10000001; j += i)
			sum[j] += i;
	}

	for (int i = 10000000; i > 0; i--)
		if (sum[i] < 10000001)
			ans[sum[i]] = i;
}

void inline solve()
{
	int n;
	cin >> n;
	cout << ans[n] << '\n';
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