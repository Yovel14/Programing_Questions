#include<iostream>
#include<vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


	// n participants
	// the i th choose the ith paricipant choose the number a[i] as winner

	int t, n, temp, ans;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> count(n+1,0);
		vector<int> index(n+1,0);
		for(int i = 1;i<=n;++i){
			cin>>temp;
			++count[temp];
			index[temp] = i;
		}
		


		ans = -1;
		for(int i = 1; i<=n;++i)
			if(count[i] == 1){
				ans = index[i];
				break;
			}
		cout<<ans<<'\n';

	}


	return 0;
}