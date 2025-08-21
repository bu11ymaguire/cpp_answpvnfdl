#include<iostream>
#include<vector>
using namespace std;

class UnionFind
{
    private:
    vector<int> parents;
    vector<int> rank;
    public:
    UnionFind(int n)
    {
        parents.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
    }
    int find(int x)
    {
        if(parents[x]!=x)
        {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX!=rootY)
        {
            if(rank[rootX]>rank[rootY])
            {
                parents[rootY] = rootX;
            }
            else if(rank[rootX]<rootY)
            {
                parents[rootX] = rootY;
            }
            else
            {
                parents[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool is_union(int x, int y)
    {
        return find(x)==find(y);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_edge, city;
    cin>>total_edge>>city;

    UnionFind uf(total_edge);
    vector<vector<int>> hello(total_edge+1,vector<int>(total_edge+1,0));

    for(int i = 1;i<=total_edge;i++)
    {
        for(int j=1;j<=total_edge;j++){
            cin>>hello[i][j];
        }
    }

    for(int i =1;i<=total_edge;i++)
    {
        for(int j=1;j<=total_edge;j++)
        {
            if(i==j) continue;
            if(hello[i][j]==1)
            {
                if(uf.is_union(i,j)) continue;
                uf.unite(i,j);
            }
        }
    }

    vector<int> route(city);
    for(int i = 0; i < city; i++){
        cin>>route[i];
    }

    bool possible = true;
    for(int i = 0; i < city-1; i++) 
    /*
    현재 여행지와 다음 여행지의 조상이 같다 == 현재 여행지에서 다음 여행지로 어쨌든 갈 수 있다
    -> 이런 식으로 route[]의 첫번쨰 목적지부터 마지막 목적지까지 탐색! 중간에 한개라도 조상이 다른 곳이 있다면, 이 관광지는 갈 수 없음!
    */
    {
        int now  = route[i];
        int next = route[i+1];
        if(!uf.is_union(now,next))
        {
            possible = false;
            break;
        }
    }

    if(possible)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
