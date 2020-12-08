#include<iostream>
#include<vector>
#include<limits.h>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FastIO;

	// sliding window seams to be possible
	int n,k;
	cin>>n>>k;
	vector<int> h(n);
	for(int &it:h) cin>>it;
	
	int min_sum = INT_MAX,sum = 0, min_index = 0;
	for(int i = 0; i < k-1 && i<n; ++i)
		sum+=h[i];
	
	for(int i = 0;i<n-k+1;++i)
	{
		sum+=h[i+k-1];
		if(sum<min_sum)
		{
			min_sum = sum;
			min_index = i;
		}
		sum-=h[i];
	}
	cout<<min_index+1;

	return 0;
}