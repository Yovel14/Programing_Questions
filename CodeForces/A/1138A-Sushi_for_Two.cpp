#include<iostream>
#include<vector>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    //n pieces of sushi
    // 1 for tuna 
    // 2 for eel
    //
    // find the length of the largest segment that can be devided  by two to have as mych 1 as 2 like 1 1 2 2 but not 1 2 1 2


    int n;
    int m = 0;
    int b1 = 0, b2 = 0;
    int count = 1;
    cin >>n;
    int now,last;
    if (n>0)
        cin>>last;
    while(cin>>now)
    {
        if (last!=now){
            b1 = b2;
            b2 = count;
            count = 1;
            m = max(m,min(b1,b2));
        }
        else ++count;
        last =now ;
    }

    b1 = b2;
    b2 = count;
    count = 1;
    m = max(m,min(b1,b2));


    cout<<m*2;
    


    return 0;
    /*
    int n;
    int m = 0;
    int b1 = 0, b2 = 0;
    int count = 1;
    cin >>n;
    vector<int> a(n);
    if (n>0)
        cin>>a[0];
    for(int i = 0;i<n;++i)
    {
        cin>>a[i];
        if (a[i]!=a[i-1]){
            b1 = b2;
            b2 = count;
            count = 1;
            m = max(m,min(b1,b2));
        }
        else ++count;
    }
    b1 = b2;
    b2 = count;
    count = 1;
    m = max(m,min(b1,b2));


    cout<<m*2;
    


    return 0;
*/
}