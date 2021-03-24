#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
using namespace std;

main()
{
	FastIO;

	bool found11;
	bool ans;
	string s;
	int t;
	int n;

	cin >> t;
	while (t--)
	{
		cin >> s;
		n = s.size();
		found11 = false;
		ans = true;

		for (int i = 1; i < n; i++)
		{
			if (s[i] == '1' && s[i - 1] == '1')
				found11 = true;
			else if (found11 && s[i] == '0' && s[i - 1] == '0')
			{
				ans = false;
				break;
			}
		}

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}