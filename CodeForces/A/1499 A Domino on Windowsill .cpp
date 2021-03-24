#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
using namespace std;

main()
{
	FastIO;

	int t;
	int n, k1, k2;
	int w, b;

	cin >> t;
	while (t--)
	{
		cin >> n >> k1 >> k2;
		cin >> w >> b;
		if (n < (b + w) || (k1 + k2) < (2 * w) || (n - k1 + n - k2) < (2 * b))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}