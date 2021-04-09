#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

main()
{
	FastIO;

	int n;
	cin >> n;
	cout << (2 - n * n); // got the formula from braille
}