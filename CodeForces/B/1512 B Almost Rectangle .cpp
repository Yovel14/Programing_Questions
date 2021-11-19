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
	int n;
	n = 4;
	cin >> n;
	int r1 = -1, c1, r2 = -1, c2;
	char c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			if (c == '*')
			{
				if (r1 == -1)
				{
					r1 = i;
					c1 = j;
				}
				else
				{
					r2 = i;
					c2 = j;
				}
			}
		}

	int r3, r4, c3, c4;
	if (r1 == r2)
	{
		c3 = c1;
		c4 = c2;
		if (r1 + 1 < n)
		{
			r3 = r1 + 1;
			r4 = r1 + 1;
		}
		else
		{
			r3 = r1 - 1;
			r4 = r1 - 1;
		}
	}
	else if (c1 == c2)
	{
		r3 = r1;
		r4 = r2;
		if (c1 + 1 < n)
		{
			c3 = c1 + 1;
			c4 = c1 + 1;
		}
		else
		{
			c3 = c1 - 1;
			c4 = c1 - 1;
		}
	}
	else
	{
		r3 = r1;
		c3 = c2;

		r4 = r2;
		c4 = c1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == r1 && j == c1) || (i == r2 && j == c2) || (i == r3 && j == c3) || (i == r4 && j == c4))
				cout << "*";
			else
				cout << ".";
		}
		cout << '\n';
	}
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