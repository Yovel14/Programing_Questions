#include<iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n>2){
			for(int i = n; i>(n+1)/2;--i) cout<<i<<' ';
			for(int i = 1; i<=(n+1)/2;++i) cout<<i<<' ';

			cout<<'\n';
		}
		else {
			for(int i = n; i>0;--i) cout<<i<<' ';
			cout<<'\n';
			}
	}


	return 0;
}