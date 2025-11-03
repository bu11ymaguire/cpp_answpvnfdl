#include<bits/stdc++.h>
using namespace std;
//BOJ 31575


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int X,Y;
    cin >> X >> Y;
    vector<vector<int>> city(Y+1,vector<int>(X+1,0));
    for(int y=1; y<=Y;y++)
    {
        for(int x=1;x<=X;x++)
        {
            cin >> city[y][x];
        }
    }

    vector<vector<bool>> visited(Y+1,vector<bool>(X+1,false));

    stack<pair<int,int>> s;
    if(city[1][1]==0){cout <<"No"; return 0;} //97퍼센트 시치.
    visited[1][1] = true;
    s.push({1,1});

    while(!s.empty())
    {
        auto now_node = s.top();
        s.pop();

        if(now_node.first+1<=X){
            if(city[now_node.second][now_node.first+1]==1&&!visited[now_node.second][now_node.first+1])
            {
                visited[now_node.second][now_node.first+1] = true;
                s.push({now_node.first+1,now_node.second});
            }
        }

        if(now_node.second+1<=Y){
            if(city[now_node.second+1][now_node.first]==1&&!visited[now_node.second+1][now_node.first])
            {
                visited[now_node.second+1][now_node.first] = true;
                s.push({now_node.first,now_node.second+1});
            }
        }
    }
    if(visited[Y][X]){
        cout <<"Yes";
    } 

    else{
        cout << "No";
    }

    return 0;
}
