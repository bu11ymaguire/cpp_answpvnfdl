#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    vector<vector<char>> apt(N+1,vector<char>(N+1,0));

    for(int y=1;y<=N;y++)
    {
        string input;
        cin>>input;
        for(int i = 0 ; i <N; i++)
        {
            apt[y][i+1] = input[i];
        }
    }

    priority_queue<int,vector<int>,greater<int>> result;
    vector<vector<int>> visited(N+1,vector<int>(N+1,false));

    for(int y=1;y<=N;y++)
    {
        for(int x = 1; x <= N ; x++)
        {
            if(visited[y][x])continue;
            if(apt[y][x]=='0')continue;
            
            queue<pair<int,int>> search;
            int n=1;
            visited[y][x] = true;
            search.push({x,y});

            while(!search.empty())
            {
                auto now = search.front();
                search.pop();
                for(int i =0; i <4; i++)
                {
                    int nx = now.first + dx[i];
                    int ny = now.second + dy[i];

                    if(nx<1||nx>N||ny<1||ny>N)continue;
                    if(visited[ny][nx])continue;
                    if(apt[ny][nx]=='0')continue;

                    visited[ny][nx] = true;
                    search.push({nx,ny});
                    n++;
                }
            }
            result.push(n);
        }
    }

    cout<<result.size()<<'\n';
    while(!result.empty())
    {
        cout<<result.top()<<'\n';
        result.pop();
    }
    return 0;
}
