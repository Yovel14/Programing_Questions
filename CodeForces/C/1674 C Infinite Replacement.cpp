void inline solve(){
    string s, t;
    cin>>s>>t;

    if(t =="a"){
        cout<<1<<'\n';
    }
    else if(std::count(t.begin(),t.end(), 'a') !=0){
        cout<<-1<<'\n';
    } else
        cout<<(long long)std::pow(2,s.size())<<'\n';
    
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
