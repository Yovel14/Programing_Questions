#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

// Special types
template <typename T>
using vc = std::vector<T>;
template <class T>
using vc = std::vector<T>;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using ll = long long;

using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

void inline solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int max = 0;
	if(n>0 && s[0] != '0')
	{
		max = 1;
	}
	for(int i = 1; i<n; ++i)
	{
		if(s[i]!=s[i-1])
		{
			++max;
		}
	}

	cout<<max<<'\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	//cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}