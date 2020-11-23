#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    string a,b;

    cin>>a;
    cin>>b;

/* TLE
    int bsize = b.size();
    int asize = a.size();

    int count = 0;
    for(int j = 0; j<bsize-asize+1; ++j)
        for (int i = 0; i<asize && i+j<bsize;++i)
        {
            if( a[i] != b[i+j]) ++count ;
        }
    cout<<count;
*/
    int c1 = 0;// count for 1
    int c0 = 0;// count for 0
    int asize = a.size();
    int bsize = b.size();
    
    for(int i = 0; i<bsize-asize+1;++i){
        if (b[i]=='1') ++c1;
        else ++c0;
    }


    long long count = 0;

    int countLength = bsize-asize;
    for(int i = 0; i<asize;++i)
        if (i!=0){
            if (b[i-1]=='0') --c0;
            else --c1;

            if( b[i+countLength]=='0') ++c0;
            else ++c1;

            if (a[i] == '0') count+=c1;
            else count+=c0;
        }
        else{
            if (a[i]=='0') count+=c1;
            else count+=c0;
        }

    cout<<count;

    return 0;
}