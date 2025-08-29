#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n; 
    cin>>m>>n;

    vector<vector<int>> hello(n+1,vector<int>(m+1));
    queue<pair<int,int>> index;

    for(int y=1;y<=n;y++)
    {
        for(int x=1;x<=m;x++)
        {
            cin>>hello[y][x];
            if(hello[y][x]==1)index.push({x,y});
        }
    }

    int day = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    
    while(!index.empty())
    {
        int now_iterate = index.size();
        bool is_zero = false;

        for(int i=0; i < now_iterate ; i++)
        {
            int now_x = index.front().first;
            int now_y = index.front().second;
            index.pop();

            for(int j = 0; j < 4; j++)
            {
                int next_x = now_x + dx[j];
                int next_y = now_y + dy[j];
                if(next_x<1||next_x>m||next_y<1||next_y>n)continue;
                if(hello[next_y][next_x]==0)
                {
                    is_zero = true;
                    hello[next_y][next_x] = 1;
                    index.push({next_x,next_y});
                }
            }
        }
        if(is_zero)day++;
    }
    for(int y =1; y<=n;y++){
        for(int x=1; x<=m;x++){
            if(hello[y][x]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<day;
    return 0;
}
