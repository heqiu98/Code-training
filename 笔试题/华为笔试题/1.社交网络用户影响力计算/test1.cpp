#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int calculateResult(int M, int K, vector<vector<int>>& tu){
    queue<pair<int,int>> q;
    vector<bool> record(1500,false);
    int result = 0;
    
    q.push({M,0});
    record[M] = true;
    
    while(!q.empty()){
        int number = q.front().first;
        int jumpNumber = q.front().second;
        q.pop();
        
        if(jumpNumber < K){
            for(int next : tu[number]){
                if(!record[next]){
                    q.push({next,jumpNumber + 1});
                    record[next] = true;
                    ++result;
                }
            }
        }else{
            continue;
        }
        
    }
    return result;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> tu(1500);
    
    int final = 0;
    
    bool edge = false;
    
    for(int i = 0;i < N;++i){
        int x, y;
        cin >> x >> y;
        if (x!=y){
            tu[x].push_back(y);
            tu[y].push_back(x);
            edge = true;
        }
    }
    if(edge && K != 0){
        int result = calculateResult(M,K,tu);
        cout << result << endl;
    }else{
        cout << final << endl;
    }

    return 0;
}