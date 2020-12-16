#include <iostream>
#include <string>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FastIO;

	int t,n;
	string s;
	bool pos;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		pos = false;
		for(int i = 0; i<=4;++i)
			if(s.substr(0,i)+s.substr(n-(4-i),4-i) == "2020")
			{
				pos = true;
				break;
			}
		if(pos) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}

	return 0;
}