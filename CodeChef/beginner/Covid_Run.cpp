#include<iostream>
#include<vector>


using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // I will try runint around until I come back to a previusly calculated value or until I get to y

    // n cities numbers from 0 to (n-1)
    int t,n,x,y,k;
    int tsize;
    bool was_infected;
    cin>>t;

    while(t--){//k size of jumps // x current city // y city you live in
        cin>>n>>k>>x>>y;
        vector<bool> infected(n);
        
        for(int i = 0;i<n;++i) infected[i]=false;


        while(!infected[x]&&!infected[y]){
            infected[x] = true;
            x = (x+k)%n;
        }
        if (infected[y]) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }





    return 0;
}