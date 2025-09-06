#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin>>N;

    vector<vector<int>> hello(N+1,vector<int>(N+1,0));
    for(int y = 1 ; y <= N; y++)
    {
        for(int x =1; x <= N; x++)
        {
            cin>>hello[y][x];
        }
    }

    vector<vector<int>> divide(N+1,vector<int>(N+1,0));
    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));

    int div = 0;
    for(int y =1; y <=N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            if(visited[y][x]||hello[y][x]==0)continue;
            div++;
            visited[y][x] = true;
            divide[y][x] = div;
            queue<pair<int,int>> now_node;
            now_node.push({x,y});

            while(!now_node.empty())
            {
                auto xy = now_node.front();
                now_node.pop();
                
                for(int i = 0 ; i < 4 ; i++)
                {
                    int X = xy.first + dx[i];
                    int Y = xy.second + dy[i];

                    if(X<1||X>N||Y<1||Y>N)continue;
                    if(visited[Y][X]||hello[Y][X]==0)continue;
                    visited[Y][X] = true;
                    divide[Y][X] = div;
                    now_node.push({X,Y});
                }
            }
        }
    }

    int min_distance = INT_MAX;
    for(int DIV = 1; DIV <= div; DIV++) //출발점이 여러개인 BFS
    {
        vector<vector<int>> distance(N+1,vector<int>(N+1,-1));

        queue<pair<int,int>> traversal;

        for(int y=1;y<=N;y++)
        {
            for(int x=1;x<=N;x++)
            {
                if(divide[y][x]==DIV)
                {
                    distance[y][x] = 0;
                    traversal.push({x,y});
                }
            }
        }

        bool find_short = false;

        while(!traversal.empty())
        {
            auto NOW = traversal.front();
            traversal.pop();

            for(int i = 0; i < 4; i++)
            {
                int X = NOW.first + dx[i];
                int Y = NOW.second + dy[i];

                if(X<1||X>N||Y<1||Y>N) continue;
                if(distance[Y][X]!=-1) continue;
                if(divide[Y][X]==DIV) continue;
                distance[Y][X] = distance[NOW.second][NOW.first] + 1;
                if(divide[Y][X]!=0)
                {
                    min_distance = min(min_distance,distance[Y][X]);
                    find_short = true;
                    break;
                }
                traversal.push({X,Y});
            }
            if(find_short) break;
        }
    }
    cout<<min_distance-1; // 섬 1 - 바다 - 바다 - 섬2 : 의 다리 길이는 min_distance - 1
    return 0;
}
