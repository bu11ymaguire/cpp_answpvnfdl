#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Y,X,question; 
    cin>>Y>>X>>question;

    vector<vector<int>> hello(Y,vector<int>(X,0));

    while(question--)
    {
        int from_x,from_y;
        cin>>from_x>>from_y;

        int to_x,to_y;
        cin>>to_x>>to_y;
        
        for(int y = from_y; y < to_y ; y++)
        {
            for(int x = from_x ; x < to_x; x++){
                hello[y][x] = 1;
            }
        }
    }

    priority_queue<int,vector<int>,greater<int>> result;
    vector<vector<bool>> visited(Y,vector<bool>(X,false));

    for(int y=0;y<Y;y++)
    {
        for(int x=0;x<X;x++)
        {
            if(visited[y][x])continue;
            if(hello[y][x]==1)continue;
            int area =1;
            visited[y][x] = true;
            queue<pair<int,int>> traverse;
            traverse.push({x,y});

            while(!traverse.empty())
            {
                auto hi = traverse.front();
                traverse.pop();

                for(int i = 0; i <4; i++)
                {
                    int nx = hi.first+dx[i];
                    int ny = hi.second+dy[i];

                    if(nx<0||nx>=X||ny<0||ny>=Y) continue;
                    if(visited[ny][nx]) continue;
                    if(hello[ny][nx]==1) continue;

                    visited[ny][nx] = true;
                    traverse.push({nx,ny});
                    area++;
                }
            }
            result.push(area);
        }
    }

    cout<<result.size()<<'\n';
    while(!result.empty())
    {
        cout<<result.top()<<' ';
        result.pop();
    }

    return 0;
}
