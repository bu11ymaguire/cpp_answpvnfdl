#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    for(int i =0; i < T ; i++)
    {
        int X,Y,grass; 
        cin>>X>>Y>>grass;
        int result = 0;
        vector<vector<int>> maze(Y,vector<int>(X,0));
        vector<vector<bool>> visited(Y,vector<bool>(X,false));
        for(int j = 0; j < grass; j++)
        {
            int x,y;
            cin>>x>>y;
            maze[y][x] = 1;
        }

        for(int y=0;y<Y;y++)
        {
            for(int x=0;x<X;x++)
            {
                if(maze[y][x]==1&&!visited[y][x])
                {
                    result++;
                    queue<pair<int,int>> hello;
                    visited[y][x] = true;
                    hello.push({x,y});
                    while(!hello.empty())
                    {
                        auto now = hello.front();
                        hello.pop();

                        for(int k =0; k < 4; k++)
                        {
                        
                            int nx = now.first + dx[k];
                            int ny = now.second + dy[k];

                            if(nx<0||nx==X||ny<0||ny==Y)continue;
                            if(visited[ny][nx]||maze[ny][nx]==0)continue;
                            visited[ny][nx] = true;
                            hello.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout<<result<<'\n';
    }
    return 0;
}
