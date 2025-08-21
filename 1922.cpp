#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class UnionFind
{
    private:
    vector<int> parent;
    vector<int> rank;

    public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0; i <=n ; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return false;

        if(rank[rootX]>rank[rootY])
        {
            parent[rootY] = rootX;
        }

        else if(rank[rootX]<rank[rootY])
        {
            parent[rootX] = rootY;
        }

        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
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
    int node,edge;
    cin>>node>>edge;

    vector<pair<int,pair<int,int>>> Edges;
    for(int i = 0; i < edge; i++)
    {
        int from,to,weight;
        cin>>from>>to>>weight;
        Edges.push_back({weight,{from,to}});
    }

    UnionFind uf(node);
    long long total = 0;
    int trying = 0;

    sort(Edges.begin(),Edges.end());

    for(const auto& hello: Edges)
    {
        int now_weight = hello.first;
        int now_from = (hello.second).first;
        int now_to = (hello.second).second;
        if(uf.unite(now_from,now_to))
        {
            total += now_weight;
            trying++;
        }
        if(trying==node-1)break;
    }
    cout<<total;
    return 0;
}
