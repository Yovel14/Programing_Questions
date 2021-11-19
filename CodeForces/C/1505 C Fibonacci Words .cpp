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

	string s;
	cin >> s;
	int n = s.size();
	bool flag = true;
	for (int i = 2; i < n; i++)
	{
		if ((s[i - 1] - 'A' + s[i - 2] - 'A') % 26 != (s[i] - 'A'))
		{
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";
}