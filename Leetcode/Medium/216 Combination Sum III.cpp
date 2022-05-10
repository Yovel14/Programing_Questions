void solve(int k, int n, int index, int lastNum, int sum, vector<int> &tsol, vector<vector<int>> &sol){
    if(sum > n || (sum != n && index == k)){
        return;
    }

    if(sum == n && index ==k){
        sol.push_back(tsol);
        return;
    }

    for(int currentNum = lastNum-1; currentNum>0; currentNum--){
        tsol[index] = currentNum;
        solve(k,n,index+1,currentNum,sum+currentNum,tsol,sol);
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> tsol(k);
    vector<vector<int>> sol;
    solve(k,n,0,10,0,tsol,sol);
    return sol;
}
