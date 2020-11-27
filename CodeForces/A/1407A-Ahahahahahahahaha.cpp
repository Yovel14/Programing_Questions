#include<iostream>
#include<vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a(n);
		vector<int> out;
		for(int &i:a) cin>>i;

		for(int i = 0; i<n;i+=4){
			if(i+3<n){
				if(a[i] + a[i+1] + a[i+2]+ a[i+3] >=2){
					out.push_back(1);
					out.push_back(1);
				}
				else
				{
					out.push_back(0);	
					out.push_back(0);	
				}
			}
			else
			{
				if(a[i]+a[i+1]==2){
					out.push_back(1);
					out.push_back(1);
				}
				else{
					out.push_back(0);
				}
			}
		}

		cout<<out.size()<<'\n';
		for(int i = 0; i< out.size(); ++i) cout<<out[i]<<' ';
		cout<<'\n';
	}

	return 0;
}