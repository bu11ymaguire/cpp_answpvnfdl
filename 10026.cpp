#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N; cin>>N;
    vector<vector<char>> RGB(N+1,vector<char>(N+1));
    vector<vector<char>> GB(N+1,vector<char>(N+1));
    vector<vector<bool>> n_visited(N+1,vector<bool>(N+1,false));
    vector<vector<bool>> ab_visited(N+1,vector<bool>(N+1,false));

    for(int y=1;y<=N;y++)
    {
        string input;
        cin>>input;
        for(int x=0;x<N;x++)
        {
            RGB[y][x+1] = input[x];
            if(input[x]=='R')GB[y][x+1] = 'G';
            else GB[y][x+1] = input[x];
        }
    }

    int n_color = 0;  
    for(int y=1;y<=N;y++)
    {
        for(int x=1;x<=N;x++)
        {
            if(n_visited[y][x]) continue;
            char now_color = RGB[y][x];
            n_visited[y][x] = true;
            queue<pair<int,int>> normal;
            normal.push({x,y});
            n_color++;

            while(!normal.empty())
            {
                auto now = normal.front();
                normal.pop();

                for(int i=0; i<4;i++)
                {
                    int nx = now.first + dx[i];
                    int ny = now.second + dy[i];

                    if(nx<1||nx>N||ny<1||ny>N) continue;
                    if(n_visited[ny][nx]||RGB[ny][nx]!=now_color) continue;
                    n_visited[ny][nx] = true;
                    normal.push({nx,ny});
                }
            }
        }
    }

    int ab_color = 0;
    for(int y=1;y<=N;y++)
    {
        for(int x=1;x<=N;x++)
        {
            if(ab_visited[y][x]) continue;
            char now_color = GB[y][x];
            ab_visited[y][x] = true;
            queue<pair<int,int>> ab_normal;
            ab_normal.push({x,y});
            ab_color++;

            while(!ab_normal.empty())
            {
                auto now = ab_normal.front();
                ab_normal.pop();

                for(int i=0; i<4;i++)
                {
                    int nx = now.first + dx[i];
                    int ny = now.second + dy[i];

                    if(nx<1||nx>N||ny<1||ny>N) continue;
                    if(ab_visited[ny][nx]||GB[ny][nx]!=now_color) continue;
                    ab_visited[ny][nx] = true;
                    ab_normal.push({nx,ny});
                }
            }
        }
    }
    cout<<n_color<<' '<<ab_color;
    return 0;
}
