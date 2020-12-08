#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <utility>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;


int main()
{
	FastIO;

	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int mx = 0;
		cin>>s;
		int n = s.size();
		vector<int> v;
		v.push_back(0);
		for(int i  = 0; i<n;++i)
		{
			if(s[i] == 'R') v.push_back(i+1);
		}
		v.push_back(n+1);
		n = v.size();
		for(int i = 0; i<n-1;++i)
		{
			if(v[i+1]-v[i]>mx) mx = v[i+1]-v[i];
		}
		cout<<mx<<'\n';
	}

	return 0;
}