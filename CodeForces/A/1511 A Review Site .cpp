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

void inline preCampute() {}

void inline solve()
{
	int n;
	cin >> n;
	int count = 0;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 1 || tmp == 3)
			count++;
	}
	cout << count << '\n';
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