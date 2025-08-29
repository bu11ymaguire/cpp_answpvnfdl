#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Y,X; cin>>Y>>X;

    vector<vector<char>> hello(Y+1,vector<char>(X+1));
    vector<vector<int>> fire_time(Y+1,vector<int>(X+1,-1));
    vector<vector<int>> jihoon_time(Y+1,vector<int>(X+1,-1));

    queue<pair<int,int>> jihoon;
    queue<pair<int,int>> fire;

    for(int y=1; y<=Y;y++)
    {
        string input;
        cin>>input;
        for(int x=0;x<X;x++)
        {
            hello[y][x+1] = input[x];
            if(input[x]=='J'){jihoon.push({x+1,y});jihoon_time[y][x+1]=0;}
            if(input[x]=='F'){fire.push({x+1,y});fire_time[y][x+1]=0;}
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    while(!fire.empty())
    {
        int fire_x = fire.front().first;
        int fire_y = fire.front().second;
        int now_time = fire_time[fire_y][fire_x];
        fire.pop();
        for(int i =0; i < 4; i++)
        {
            int next_fx = fire_x + dx[i];
            int next_fy = fire_y + dy[i];

            if(next_fx<1 || next_fx>X || next_fy<1 || next_fy>Y)continue;
            if(hello[next_fy][next_fx]=='#')continue;
            if(fire_time[next_fy][next_fx]!=-1)continue;
            
            fire_time[next_fy][next_fx] = now_time+1;
            fire.push({next_fx,next_fy});
        }
    }

    while(!jihoon.empty())
    {
        int jihoon_x = jihoon.front().first;
        int jihoon_y = jihoon.front().second;
        int now_time = jihoon_time[jihoon_y][jihoon_x];
        jihoon.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int next_jx = jihoon_x + dx[i];
            int next_jy = jihoon_y + dy[i];

            if(next_jx<1 || next_jx>X || next_jy <1 || next_jy>Y)
            {
                cout<<now_time+1;
                return 0;
            }

            if(hello[next_jy][next_jx]=='#')continue;
            if(jihoon_time[next_jy][next_jx]!=-1)continue;

            if(fire_time[next_jy][next_jx]==-1||fire_time[next_jy][next_jx]>now_time+1) //불이 도달하지 않는 곳(-1)에 대한 조건 추가!
            {
                jihoon_time[next_jy][next_jx] = now_time+1;
                jihoon.push({next_jx,next_jy});
            }
        }
    }
    
    cout<<"IMPOSSIBLE";
    return 0;
}
