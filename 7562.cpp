#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,-2,2,1,-1,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;

    while(T--)
    {
        int X; 
        cin>>X;
        vector<vector<int>> hello(X,vector<int>(X,0));
        vector<vector<bool>> visited(X,vector<bool>(X,false));

        int from_X,from_Y;
        cin>>from_X>>from_Y;

        int to_X,to_Y;
        cin>>to_X>>to_Y;

        if(from_X==to_X&&from_Y==to_Y)
        {
            cout<<0<<'\n';
            continue;
        }

        queue<pair<int,pair<int,int>>> now_index;
        visited[from_Y][from_X] = true;
        now_index.push({0,{from_X,from_Y}});

        while(!now_index.empty())
        {
            auto now = now_index.front();
            now_index.pop();

            for(int i = 0; i <8 ; i++)
            {
                int nx = now.second.first + dx[i];
                int ny = now.second.second + dy[i];

                if(nx<0||nx>=X||ny<0||ny>=X)continue;
                if(visited[ny][nx])continue;
                if(ny==to_Y&&nx==to_X)
                {
                    visited[to_Y][to_X] = true;
                    break;
                }
                visited[ny][nx] = true;
                now_index.push({now.first+1,{nx,ny}});
            }

            if(visited[to_Y][to_X])
            {
                cout<<now.first+1<<'\n';
                break;
            }
        }
    }

    return 0;
}
