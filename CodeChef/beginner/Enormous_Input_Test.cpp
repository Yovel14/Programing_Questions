#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,temp, count = 0;
    cin>>n>>k;
    while (cin>>temp){
        if (temp%k==0)++count;
    }
    cout<<count;

    return 0;
}