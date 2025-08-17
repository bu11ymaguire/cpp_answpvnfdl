#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m; //m-> x축 n -> y축
    vector<vector<int>> maze(n+1,vector<int>(m+1,0));  ///******이러면 maze[y][x] 형태로 사용해야됨!

    for(int i = 1; i <= n ; i++)
    {
        string data;
        cin>>data;
        for(int j = 0; j<m;j++)
        {
            if(data[j]=='1')
            {
                maze[i][j+1]=1;
            }
        }
    }

    vector<vector<int>> distance(n+1,vector<int>(m+1,-1));
    queue<pair<int,int>> now_node;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    
    distance[1][1] = 1;
    now_node.push({1,1});

    while(!now_node.empty())
    {
        int current_x = now_node.front().first;
        int current_y = now_node.front().second;
        now_node.pop();
        
        for(int i = 0 ; i < 4; i ++)
        {
            int temp_x = current_x + dx[i];
            int temp_y = current_y + dy[i];
            if(temp_x>m||temp_x<1||temp_y>n||temp_y<1) continue; 
            if(maze[temp_y][temp_x]==0) continue;
            if(distance[temp_y][temp_x]!=-1) continue;
            distance[temp_y][temp_x] = distance[current_y][current_x] + 1;
            now_node.push({temp_x,temp_y});
        }
    }
    cout<<distance[n][m];

    return 0;
}
