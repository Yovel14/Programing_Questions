#include<iostream>
#include<vector>
#include<math.h>


using namespace std;


void solve(){

    string str;
    cin>>str;
    
    long long int len = str.length();

    string ns = str;
    for(long long int i = len/2; i<len;++i) ns[i] = ns[len-i-1];

    if( ns>str){
        cout<<ns<<'\n';
        return;
    }
    for( long long int i = (len-1)/2;i >=0;--i){
        if(ns[i] == '9')
            ns[i] = '0';
        else{
            ++ns[i];
            break;
        }
    }
    
    for(long long int i = len/2; i<len;++i) ns[i] = ns[len-i-1];

    if(ns[0] == '0'){
        ns+='1';
        ns[0] = '1';
    }


    cout<<ns<<'\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}