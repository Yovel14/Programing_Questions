void inline solve(){
    string n;
    cin>>n;
    int first = 0, last = 0;
    for(int i = 0; i<3; i++){
        first+=n[i]-'0';
    }
    for(int i = 3; i<6; i++){
        last+=n[i]-'0';
    }
    if(first == last){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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
