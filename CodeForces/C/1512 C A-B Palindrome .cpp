#include <iostream>
#include <vector>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void inline solve()
{
	int a, b;
	string str;
	cin >> a >> b >> str;
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0')
			a--;
		else if (str[i] == '1')
			b--;
	}

	int s = 0, e = n - 1;
	bool possible = true;
	while (s < e)
	{
		if (str[s] == '?' && str[e] != '?')
		{
			if (str[e] == '0')
			{
				if (a == 0)
				{
					possible = false;
					break;
				}
				str[s] = '0';
				a--;
			}
			else
			{
				if (b == 0)
				{
					possible = false;
					break;
				}
				str[s] = '1';
				b--;
			}
		}
		else if (str[e] == '?' && str[s] != '?')
		{
			if (str[s] == '0')
			{
				if (a == 0)
				{
					possible = false;
					break;
				}
				str[e] = '0';
				a--;
			}
			else
			{
				if (b == 0)
				{
					possible = false;
					break;
				}
				str[e] = '1';
				b--;
			}
		}
		if (str[s] != str[e])
		{
			possible = false;
			break;
		}

		s++;
		e--;
	}

	for (s = 0, e = n - 1; possible && s < e; s++, e--)
	{
		if (str[s] == '?' && str[e] == '?')
		{
			if (a > b)
			{
				if (a < 2)
				{
					possible = false;
					break;
				}
				str[s] = '0';
				str[e] = '0';
				a -= 2;
			}
			else
			{
				if (b < 2)
				{
					possible = false;
					break;
				}
				str[s] = '1';
				str[e] = '1';
				b -= 2;
			}
		}
	}

	if (possible && str[s] == '?')
	{
		if (a)
		{
			a--;
			str[s] = '0';
		}
		else if (b)
		{
			b--;
			str[s] = '1';
		}
		else
		{
			possible = false;
		}
	}

	if (possible && a == 0 && b == 0)
		cout << str << '\n';
	else
		cout << -1 << '\n';
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