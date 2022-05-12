void inline solve(){
    int n;
    cin>>n;
    bool a[101] = {0};
    int n0 = 0;
    bool duplicate = false;
    int t;
    bool zero = false;
    int ans = 0;
    for(int i=  0; i<n; i++){
        cin>>t;
        if(t!=0){
            n0++;
        }
        if(a[t]){
            duplicate = true;
        }
        a[t] = true;
    }

    if(a[0]){
        cout<<n0<<'\n';
    }else if(duplicate){
        cout<<(n)<<'\n';
    }else{
        cout<<(n+1)<<'\n';
    }
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
