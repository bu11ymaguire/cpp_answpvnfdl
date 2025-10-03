#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string one,two,three; cin >> one >> two >> three;
    int X = one.length(); int Y = two.length(); int Z = three.length();
    vector<vector<vector<int>>> DP(X+1,vector<vector<int>>(Y+1,vector<int>(Z+1)));
    for(int x = 1; x <= X; x++)
    {
        for(int y = 1; y <=Y; y++)
        {
            for(int z = 1; z <=Z; z++)
            {
                if((one[x-1]==two[y-1])&&(two[y-1]==three[z-1])) //논리연산자 사용 주의!
                {
                    DP[x][y][z] = DP[x-1][y-1][z-1] + 1;
                }
                else
                {
                    DP[x][y][z] = max(DP[x-1][y][z],max(DP[x][y-1][z],DP[x][y][z-1]));
                }
            }
        }
    }
    cout <<DP[X][Y][Z];
    return 0;
}
