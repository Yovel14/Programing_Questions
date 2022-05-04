// solution 1
// brute force
// time : O(y^2)
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

// solution 2
// math
// Time : O(1)
/*
b*X^a = y
in order for there to be a solution y must be devisible by  both x^a and b and sense a and b can be 1 we can always set it to one thus y must only be devisible by x
*/
void solve(){
    int x,y;
    cin>>x>>y;
    
    if(y%x)
        cout<< 0 <<' '<< 0 <<'\n';
    else cout << 1<< ' '<< (y/x)<<'\n';
}

int main (){
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
}
