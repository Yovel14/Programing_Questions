#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;
void solve()
{
}

main()
{
	FastIO;

	int n;
	cin >> n;
	if (n == 0)
		cout << 0;
	else
	{
		int tmp = n % 9;
		cout << (tmp == 0 ? 9 : tmp);
	}
}