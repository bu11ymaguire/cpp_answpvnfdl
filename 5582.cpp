#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string one, two; cin >> one >> two;
    int X = one.length(); int Y = two.length();

    vector<vector<int>> DP(X,vector<int>(Y,0));

    priority_queue<int> pq;
    pq.push(0);

    for(int x = 0; x < X; x++)
    {
        for(int y = 0; y < Y; y++)
        {
            if(one[x]!=two[y])continue;
            else
            {
                if(DP[x][y]!=0)continue;
                int i = x; int j = y;
                int tmp = 0;
                while(i<X||j<Y)
                {
                    if(one[i]==two[j]){
                        tmp++;
                        DP[i][j] = tmp;
                        i++; j++;
                    }else
                    {
                        break;
                    }
                }
                pq.push(tmp);
            }
        }
    }
    cout << pq.top();
    return 0;
}
