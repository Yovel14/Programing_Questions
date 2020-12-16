#include<iostream>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


int max_digit(int n)
{
	int mx = 0;
	while(n)
	{
		mx = max(mx,n%10);
		n/=10;
	}
	return mx;
}
int main()
{
	FastIO;

	// substruct a digit from number (which acures in it) and get a new magic number
	// do so until you get 0
	int n,n2,count = 0;
	cin>>n;
	n2 = n;

	while(n)
	{
		n -=max_digit(n);
		++count;
	}
	cout<<count;

	return 0;
}