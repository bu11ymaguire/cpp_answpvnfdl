#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> hello;
vector<vector<int>> dp;

int X;
int Y;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int return_dp(int x, int y)
{
    if(y==Y&&x==X)
    {
        return 1;
    }
    
    if(dp[y][x]!=-1)
    {
        return dp[y][x];
    }

    dp[y][x] = 0;
    for(int i = 0; i < 4; i ++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x<1||new_x>X||new_y<1||new_y>Y)continue;
        if(hello[new_y][new_x]<hello[y][x])
        {
            dp[y][x] += return_dp(new_x,new_y);
        } 
    }

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Y >> X;

    hello.assign(Y+1,vector<int>(X+1));
    dp.assign(Y+1,vector<int>(X+1,-1));

    for(int y=1;y<=Y;y++)
    {
        for(int x=1;x<=X;x++)
        {
            cin >> hello[y][x];
        }
    }

    cout << return_dp(1,1);
    return 0;
}
