#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
void solve(vector<int> &v){
    int s1,s2;
    s1=s2=0;
    for (auto i =  v.rbegin(); i != v.rend(); ++i){
        if (s1>s2) s2+=*i;
        else s1+=*i;
    }
    cout<<max(s1,s2)<<'\n';
}


int main(){
    // T number of tests
    //integer N 
    // N space separated integers

    int T;
    cin>>T;
    for(int i = 0; i<T;++i){
        int n;
        cin>>n;
        vector<int> v(n);
        for (int &j:v) cin>>j; 
        sort(v.begin(),v.end());
        solve(v);
    }
}