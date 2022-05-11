void inline solve(){
    int n;
    cin>>n;
    int can[n];
    int min = INT_MAX;
    for(int i = 0; i<n; i++){
        cin>>can[i];
        min = std::min(min, can[i]);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans+=(can[i]-min);
    }

    cout<<ans<<'\n';
}

void inline preCalc(){
}

int main (){
    FastIO;
    preCalc();
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
}
