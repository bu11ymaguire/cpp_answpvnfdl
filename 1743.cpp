#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n,m,T;
    cin>>n>>m>>T;
    vector<vector<int>> maze(n+1,vector<int>(m+1,0));
    vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));

    for(int i = 0; i < T ; i++)
    {
        int y,x;
        cin>>y>>x;
        maze[y][x]=1;
    }

    priority_queue<int> hello;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    for(int y = 1; y <=n ; y++)
    {
        for(int x = 1; x <=m ; x++)
        {
            if(maze[y][x]==1&&!visited[y][x])
            {
                queue<pair<int,int>> now_node;
                int volume = 0;
                visited[y][x] = true;
                now_node.push({y,x});
                while(!now_node.empty())
                {
                    auto current = now_node.front();
                    now_node.pop();
                    volume++;

                    int Y = current.first;
                    int X = current.second;

                    for(int i =0; i<4;i++)
                    {
                        int next_Y = Y + dy[i];
                        int next_X = X + dx[i];

                        if(next_Y<1 || next_Y>n ||next_X < 1 || next_X > m ) continue;
                        if(visited[next_Y][next_X]) continue;
                        if(maze[next_Y][next_X]!=1) continue;

                        visited[next_Y][next_X] = true;
                        now_node.push({next_Y,next_X});
                    }
                }
                hello.push(volume);
            }
        }
    }
    if(hello.empty())cout<<0;
    else cout<<hello.top();
    return 0;
}
