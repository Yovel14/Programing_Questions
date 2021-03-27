#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstddef>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
using namespace std;

// Time : O(n)
main()
{
	FastIO;

	int ctc;
	cin >> ctc;
	while (ctc--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int count = 0;
		int firstIndex = s.find_first_of('*');
		if (firstIndex != string::npos)
		{
			count = 1;

			int i = firstIndex;
			int j = -1;
			while (true)
			{
				j = min(i + k, n - 1);
				for (; j != i && s[j] == '.'; j--)
					;
				if (i == j)
					break;
				count++;
				i = j;
			}
		}
		cout << count << '\n';
	}
}

// Time : O(n*k) for each test case
main()
{
	FastIO;

	//
	int ctc;
	ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		int n, k;
		n = 7, k = 3;
		cin >> n >> k;
		string s;
		s = ".**.***";
		cin >> s;
		int count = 0;
		int firstIndex = -1;
		int lastIndex = -1;
		for (int i = (n - 1); i != -1; i--)
			if (s[i] == '*')
			{
				s[i] = 'x';
				lastIndex = i;
				count++;
				break;
			}
		for (int i = 0; i < n; i++)
			if (s[i] == '*')
			{
				s[i] = 'x';
				firstIndex = i;
				count++;
				break;
			}

		if (firstIndex != -1 && lastIndex != -1)
		{
			int furIndex;
			int limit = lastIndex + 1;
			int i = firstIndex + 1;
			while (i < limit)
			{
				furIndex = n;
				for (int j = 0; j < k && i < limit; i++, j++)
				{
					if (s[i] == '*')
						furIndex = i;
					else if (s[i] == 'x')
						furIndex = n;
				}
				if (furIndex != n)
				{
					count++;
					s[furIndex] = 'x';
					i = furIndex + 1;
				}
			}
		}
		cout << count << '\n';
	}
}
