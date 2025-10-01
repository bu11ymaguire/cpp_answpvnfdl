#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string one,two; cin >> one >> two;
    int X = one.length(); int Y = two.length();

    vector<vector<int>> dp(Y+1,vector<int>(X+1,0));
    for(int i = 1; i <= X; i++)
    {
        for(int j =1; j<=Y; j++)
        {
            if(one[i-1]==two[j-1])
            {
                dp[j][i] = dp[j-1][i-1]+1;
            }
            else
            {
                dp[j][i] = max(dp[j-1][i],dp[j][i-1]);
            }
        }
    }

    int x=X, y= Y;
    stack<char> output;

    while(x!=0&&y!=0)
    {
        if(one[x-1]==two[y-1])
        {
            output.push(one[x-1]);
            x--;
            y--;
        }
        else
        {
            if(dp[y-1][x]>=dp[y][x-1])
            {
                y--;
            }

            else
            {
                x--;
            }
        }
    }

    cout << output.size() << '\n';
    while(!output.empty())
    {
        cout << output.top();
        output.pop();
    }
    return 0;
}
