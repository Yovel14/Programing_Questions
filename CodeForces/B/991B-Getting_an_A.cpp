#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


	int n;
	float sum = 0;
	cin>>n;
	int arr[n] = {0};
	for(int i = 0; i<n; ++i) {
		cin>>arr[i];
		sum+=arr[i];
		}

	if(round(sum/n)!=5){
		int count = 0;
		sort(arr,arr+n);
		int i = 0;
		while(round(sum/n)!=5 &&i<n){
			sum+=-arr[i]+5;

			++count;
			++i;
		}
		cout<<count<<'\n';

		

	}
	else cout<<0<<'\n';

	return 0;
}