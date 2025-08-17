#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;cin>>n>>m; //n: y축, m: x축

    vector<vector<int>> hello(n+1,vector<int>(m+1,0));  // 1- base : hello[y축][x축]
    vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));
    queue<pair<int,int>> search;

    for(int i=1;i<=n;i++)
    {
        string input;
        cin>>input;
        for(int j=0;j<m;j++) // x축: j+1, y축: i
        {
            if(input[j]=='I')
            {
                search.push({j+1,i});
                visited[i][j+1] = true;
            }
            else if(input[j]=='P')
            {
                hello[i][j+1]=1;
            }
            else if(input[j]=='X')
            {
                hello[i][j+1]=-1;
            }
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    int result = 0;

    while(!search.empty()) //방문처리 누락, 배열 범위 벗어나는 경우 누락
    {
        int x = search.front().first;
        int y = search.front().second;
        search.pop();
        result += hello[y][x];
        for(int i = 0 ; i < 4; i++)
        {
            int tmp_x = x + dx[i];
            int tmp_y = y + dy[i];
            if(tmp_x>m||tmp_x<1||tmp_y>n||tmp_y<1){continue;}
            if(visited[tmp_y][tmp_x]){continue;}
            if(hello[tmp_y][tmp_x]==-1){continue;}
            search.push({tmp_x,tmp_y});
            visited[tmp_y][tmp_x] = true;
        }
    }
    if(result==0)cout<<"TT";
    else cout<<result;

    return 0;
}
