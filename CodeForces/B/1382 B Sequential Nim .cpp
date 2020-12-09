#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<algorithm>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FastIO;

	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool first = true;
		vector<int> a(n);
		for(int &it : a) cin>>it;
		
		for(int i = 0;i<n;++i)
		{
			if(a[i]==1)
				first = !first;
			else
			{
				first = !first;
				break;
			}
		}
		
		if(first)
			cout<<"Second"<<'\n';
		else
			cout<<"First"<<'\n';
	}

	return 0;
}