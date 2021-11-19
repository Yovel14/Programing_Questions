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

void inline solve()
{
	ll n, c;
	cin >> n >> c;
	vector<int> a(n);
	vector<int> b(n - 1);

	for (int i = 0; i < n; i++)
		cin >>
			a[i];

	for (int i = 0; i + 1 < n; i++)
		cin >> b[i];

	ll minDays = INT_MAX;
	ll curDays = 0;
	ll have = 0;
	for (int i = 0; i < n && c != have; i++)
	{
		minDays = min(minDays, curDays + int(ceil(double(c - have) / a[i]))); // collect the remain today
		if (i != n - 1)														  // advance a job when you can
		{
			if (have >= b[i])
			{
				have -= b[i];
				curDays++;
			}
			else
			{
				ll daysToPromotion = ceil(double(b[i] - have) / a[i]);
				have += daysToPromotion * a[i] - b[i];
				curDays += daysToPromotion + 1;
			}
		}
	}

	cout << minDays << '\n';
}

main()
{
	FastIO;

	int ctc = 1;
	cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}