#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,m;
    cin>>N>>m;
    vector<vector<int>> hello(N+1,vector<int>(N+1,0));
    vector<bool> already_visited(N+1,false);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        hello[a][b]=1;
        hello[b][a]=1; //양방향 노드 고려
    }
    int virus = 0;
    queue<int> check;
    check.push(1);
    already_visited[1]=true; //시작점인 1의 방문도 고려해야...
    while(!check.empty())
    {
        for(int i=1;i<=N;i++)
        {
            if(hello[check.front()][i]==1){
                if(!already_visited[i]){
                    check.push(i);
                    virus++;
                    already_visited[i]=true;
                }
            }
        }
        check.pop();
    }
    cout<<virus;
    return 0;
}
