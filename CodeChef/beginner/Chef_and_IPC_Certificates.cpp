#include<iostream>
#include<vector>


using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n students numberd from 1 to n 
    // watching k lectures 1 though k
    //t_ij time student i watched lecture j
    // student must watch at least m minutes of lectures in total  and not  asked the question more than 10 times

    //intput: // n - n spce sparated  lines after //m - the minimum number of lecture minutes to watch t oget certifide  //k - each like containes k+1 space seperated lectures 

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> lec(n);

    for(int i = 0;i<n;++i){
    lec[i] = vector<int>(k+1);
        for(int j =0; j<k+1;++j)
            cin>>lec[i][j];
    }
    

    int minuteCount = 0; //cont of minutes for each student
    int eligibleCount = 0; // ocunt for eligible students
    
    for(int i = 0; i<n;++i){
        minuteCount = 0;
        if (lec[i][k]>10) continue;

        for(int j = 0; j<k;++j){
            minuteCount+=lec[i][j];

            if (minuteCount>=m) break;
        }

        if (minuteCount>=m) ++eligibleCount;
    }
    cout<<eligibleCount;




    return 0;
}
/*
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> lec(n);

    for(int i = 0;i<n;++i){
    lec[i] = vector<int>(k+1);
        for(int j =0; j<k+1;++j)
            cin>>lec[i][j];
    }
    

    int minuteCount = 0; //cont of minutes for each student
    int eligibleCount = 0; // ocunt for eligible students
    
    for(int i = 0; i<n;++i){
        minuteCount = 0;
        if (lec[i][k]>10) continue;

        for(int j = 0; j<k;++j){
            minuteCount+=lec[i][j];

            if (minuteCount>m) break;
        }

        if (minuteCount<=m) ++eligibleCount;
    }
    cout<<eligibleCount;
    */