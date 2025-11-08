#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin >> N;
    vector<vector<int>> hello(N+1,vector<int>(N+1));
    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));

    for(int y =1; y <=N; y++)
    {
        for(int x=1; x<=N; x++)
        {
            cin >> hello[y][x];
        }
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1][1] = true;

    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        int x = now.first; int y = now.second;
        int X = x + hello[y][x];
        int Y = y + hello[y][x];

        if(X<=N){
            if(!visited[y][X]){
                visited[y][X] = true;
                q.push({X,y});
            }
        }
           
        if(Y<=N){
            if(!visited[Y][x]){
                visited[Y][x] = true;
                q.push({x,Y});
            }
        }
    }

    if(visited[N][N]) cout <<"HaruHaru";
    else cout <<"Hing";

    return 0;
}
