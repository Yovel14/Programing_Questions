#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

string deciToBaseN(int n, int b)
{
	string bases = "0123456789ABCDEF";
	string ans = "";
	while (n)
	{
		ans = bases[n % b] + ans;
		n /= b;
	}
	return ans;
}

main()
{
	FastIO;
	int n, m;

	cin >> n >> m;

	bool flag = true;
	bool was[127];
	memset(was, 0, sizeof(was));
	string a = deciToBaseN(n, m);
	for (char c : a)
	{
		if (was[c])
		{
			flag = false;
			break;
		}
		else
			was[c] = true;
	}

	cout << (flag ? "YES" : "NO");
}