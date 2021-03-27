#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
using namespace std;

main()
{
	FastIO;

	int ctc;
	long long n, m, x;
	cin >> ctc;
	while (ctc--)
	{
		cin >> n >> m >> x;

		long long c = (x - 1) / n;
		long long r = (x - 1) % n;
		cout << r * m + c + 1 << "\n";
	}
}
