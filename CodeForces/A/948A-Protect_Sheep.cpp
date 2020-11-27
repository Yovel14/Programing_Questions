#include<iostream>
#include<vector>


using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	
	

	int r,c;
	string temp;
	bool cant = false;
	cin>>r>>c;
	vector<string> v(r,"");

	for(string &s:v){
		cin>>s;
		for(char &c:s) if(c == '.') c = 'D';
	}

	for(int i = 0;i<r;++i){
		for( int j = 0;j<c;j++){
			if(v[i][j] == 'W'){
				if(i!=0 && v[i-1][j] =='S'){
					cant = true;
					break;
				}
				if(i!=r-1 && v[i+1][j] =='S'){
					cant = true;
					break;
				}

				if(j!=0 && v[i][j-1] =='S'){
					cant = true;
					break;
				}
				if(j!=c-1 && v[i][j+1] =='S'){
					cant = true;
					break;
				}

			}
		}
		if(cant) break;
	}



	if(cant) cout<<"No"<<'\n';
	else{
		cout<<"Yes"<<'\n';
		for(string &s:v) cout<<s<<'\n';
	}





	return 0;
}