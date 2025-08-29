#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    vector<vector<int>> hello(n+1,vector<int>(m+1,0));
    for(int y=1;y<=n;y++)
    {
        for(int x=1;x<=m;x++)
        {
            cin>>hello[y][x];
        }
    }

    vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));

    int max_area = 0;
    int painting = 0;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    for(int y = 1; y <=n ; y++)
    {
        for(int x = 1; x <= m ; x++)
        {
            if(hello[y][x]==1&&!visited[y][x])
            {
                painting++;
                int area = 1;
                queue<pair<int,int>> index; 
                visited[y][x] = true;
                index.push({x,y});

                while(!index.empty())
                {
                    int now_x = index.front().first;
                    int now_y = index.front().second;
                    index.pop();
                    for(int i = 0; i<4;i++)
                    {
                        int next_x = now_x + dx[i]; int next_y = now_y + dy[i];
                        if(next_x<1||next_x>m||next_y<1||next_y>n) continue;;
                        if(visited[next_y][next_x])continue;
                        if(hello[next_y][next_x]!=1)continue;
                        visited[next_y][next_x] = true;
                        index.push({next_x,next_y});
                        area++;
                    }
                }

                max_area = max(max_area,area);
            }
        }
    }

    cout<<painting<<'\n';
    cout<<max_area;
    return 0;
}
