#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void inline solve()
{
	int n;
	cin >> n;

	// I can make all even elements 0 for free and all odd elemnts 3 for free
	// and now I can make even elements 3 for 1 coin each or make odd elements 0 for 1 coin each so the return value is min(countEven, countOdd)
	int countOdd = 0;
	int countEven = 0;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		if (tmp & 1)
			countOdd++;
		else
			countEven++;
	}

	cout << min(countEven, countOdd) << '\n';
}

main()
{
	FastIO;

	int ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}