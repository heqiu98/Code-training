#include<iostream>
#include<vector>

using namespace std;

int main(){
    int M, N;
    vector<int> value(M);
    vector<int> weight(M);
    cin >> M >> N;
    for(int i = 0; i < M; ++i){
        cin >> weight[i]; 
    }
    for(int i = 0; i < M; ++i){
        cin >> value[i];
    }
    
    vector<vector<int>> dp(M,vector<int>(N+1,0));
    for(int j = weight[0]; j <= N; ++j){
        dp[0][j] = value[0];
    }
    
    for(int i = 1; i < M; ++i){
        for(int j = 0; j < N+1; ++j){
            if(j < weight[i]) dp[i][j] = dp[i - 1][j];
            else{ dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);}
        }
    }
    
    cout  << dp[M-1][N] << endl;
    
    return 0;
}