#include<bits/stdc++.h>
//ps에서만큼은 bits/stdc++.h 쓰자...
using namespace std;

int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,-1,1,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Y,X; cin>>Y>>X;
    vector<vector<char>> hello(Y+1,vector<char>(X+1,'0'));

    queue<pair<int,int>> Q;

    for(int y=1;y<=Y;y++)
    {
        string input;
        cin>>input;
        for(int x=1;x<=X;x++)
        {
            hello[y][x] = input[x-1];
            if(hello[y][x]=='F'){
                Q.push({x,y});
            }
        }
    }

    queue<pair<int,pair<int,int>>> O;

    while(!Q.empty())
    {
        auto info = Q.front();
        Q.pop();

        for(int i = 0; i < 8 ; i++)
        {
            int nx = info.first + dx[i];
            int ny = info.second + dy[i];
            if(nx<1||nx>X||ny<1||ny>Y)continue;
            if(hello[ny][nx]=='O')
            {
                O.push({i,{nx,ny}});
            }
        }
    }

    int foxes = 0;
    while(!O.empty())
    {
        auto info = O.front();
        O.pop();

        for(int i = 0 ; i < 8 ; i++)
        {
            if(info.first!=i)continue;
            int nx = info.second.first + dx[i];
            int ny = info.second.second + dy[i];
            if(nx<1||nx>X||ny<1||ny>Y)continue;
            if(hello[ny][nx]=='X')
            {
                foxes++;
            }
        }
    }
    cout<<foxes;
    return 0;
}
