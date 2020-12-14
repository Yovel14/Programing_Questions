#include<iostream>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FastIO;

	// discharges 2 percent each minute
	// charges 1 percent each minute connected

	// 3, 5
	// 3+1 5-2 = 4 3
	// 4-2 4+1 = 2 5
	// 2+1 5-2 = 3 3
	// 3-2 3+1 = 1 4
	// 1+1 4-2 = 2 2
	// 0 3 == GAME OVER

	int a,b, mx_temp,mn_temp,count = 0;
	cin>>a>>b;
	if(a-1>0 || b-1>0)
		while(a>0 && b>0)
		{
			mx_temp = max(a,b);
			mn_temp = min(a,b);
			a = mx_temp-2;
			b = min(mn_temp+1,100);
			++count;
		}
	cout<<count;

	return 0;
}