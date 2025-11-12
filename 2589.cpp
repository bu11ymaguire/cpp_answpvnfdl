#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y,x; cin >> y >> x;
    vector<vector<char>> MAP(y+1,vector<char>(x+1));

    for(int Y=1;Y<=y;Y++)
    {
        string input; cin >> input;
        for(int X = 0; X < x; X++)
        {
            MAP[Y][X+1] = input[X];
        }
    }

    int result = 0;

    for(int Y=1;Y<=y;Y++)
    {
        for(int X=1;X<=x;X++)
        {
            if(MAP[Y][X]=='W')continue;
            vector<vector<int>> visited(y+1,vector<int>(x+1,0)); //visited 배열을 공유하면 각각의 탐색이 제대로 진행되지 않을 수 있음.
            queue<pair<int,int>> q;
            visited[Y][X] = 1; //방문표시(BFS안에서 재방문 방지 차원),(어짜피 마지막에 출력때 -1로 해당 보정값을 지운다.)
            q.push({X,Y});
            while(!q.empty())
            {
                int nox = q.front().first;
                int noy = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int newx = nox + dx[i];
                    int newy = noy + dy[i];

                    if(newx<1||newx>x||newy<1||newy>y)continue;
                    if(MAP[newy][newx]=='W')continue;
                    if(visited[newy][newx]==0)
                    {
                        visited[newy][newx] = visited[noy][nox] + 1;
                        result = max(result,visited[newy][newx]);
                        q.push({newx,newy});
                    }
                }
            }
        }
    }

    cout << result-1;

    return 0;
}
