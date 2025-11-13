#include<bits/stdc++.h>
using namespace std;


int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};


void BFS(int x,int y, int z)
{
    vector<vector<vector<char>>> xyz(z+1,vector<vector<char>>(y+1,vector<char>(x+1)));
    vector<vector<vector<int>>> visited(z+1,vector<vector<int>>(y+1,vector<int>(x+1,-1)));
    pair<int,pair<int,int>> start;
    queue<pair<int,pair<int,int>>> q;
    for(int Z=1; Z<=z;Z++)
    {
        for(int Y=1;Y<=y;Y++)
        {
            for(int X=1;X<=x;X++)
            {
                cin >> xyz[Z][Y][X];
                if(xyz[Z][Y][X]=='S'){
                    start = {X,{Y,Z}};
                    q.push(start);
                    visited[Z][Y][X] = 0;
                } 
            }
        }
    }

    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        int n_x = now.first;
        int n_y = now.second.first;
        int n_z = now.second.second;

        for(int i = 0; i < 6; i++)
        {
            int nx = n_x + dx[i];
            int ny = n_y + dy[i];
            int nz = n_z + dz[i];
            if(nx<1||nx>x||ny<1||ny>y||nz<1||nz>z)continue;
            if(xyz[nz][ny][nx]=='#')continue;
            if(visited[nz][ny][nx]!=-1)continue;
            visited[nz][ny][nx] = visited[n_z][n_y][n_x] + 1;
            if(xyz[nz][ny][nx]=='E')
            {
                cout << "Escaped in " << visited[nz][ny][nx] << " minute(s).\n";
                return;
            }
            q.push({nx,{ny,nz}});
        }
    }
    cout << "Trapped!\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while(true)
    {
        int z,y,x; cin >> z >> y >> x;
        if(z==0&&y==0&&z==0) break;
        BFS(x,y,z);
    }
    

    return 0;
}
