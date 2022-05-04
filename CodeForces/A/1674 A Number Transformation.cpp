// brute force
void solve(){
    int x,y;
    cin>>x>>y;
    for( int a = 1; a<=y; a++){
        for(int b = 1; b<=y;b++){
            int c = b*pow(x,a);
            if(c == y){
                cout<< a<<' '<< b<<'\n';
                return;
            }
            if (c> y){
                break;
            }
        }
    }

    cout<< 0<<' '<< 0 <<'\n';
}

int main (){
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
}
