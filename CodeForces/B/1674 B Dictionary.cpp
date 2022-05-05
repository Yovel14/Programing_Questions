// math
void solve(){
    string s;
    cin>>s;
    cout << ((s[0] -'a') * 25 + (s[1]-'a' + 1) + (s[1]>s[0] ? -1 : 0))<< '\n';
}

int main (){
    FastIO;
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
}


// precalculate

std::unordered_map<string,int> indexer;

void inline solve(){
    string s;
    cin>>s;
    cout << indexer[s]<< '\n';
}

void inline preCalc(){
    int index = 1;
    for(int a = 0; a<26; a++){
        for(int b  = 0; b<26; b++){
            if(a!=b){
                string ans = "  ";
                ans[0] = 'a'+a;
                ans[1] = 'a'+b;
                indexer.insert({ans,index++});
            }
        }
    }
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
