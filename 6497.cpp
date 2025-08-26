#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
절약값이 어디서 나오는 걸까? -> 무지성 순회는 weight 값만큼의 cost가 소모되지만, mst를 통해서 적절히 순회를 하면 
(total weight - mst 값 만큼이 절약된다!)
*/

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

        for(int i = 0 ; i <= n ; i ++)
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

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return false;
        if(rank[rootX]>rank[rootY])
        {
            parents[rootY] = rootX;
        }
        else if(rank[rootX]<rank[rootY]){
            parents[rootX] = rootY;
        }
        else{
            parents[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int node,edge;

    while(cin>>node>>edge&&!(node==0&&edge==0))
    {
        UnionFind uf(node);
        vector<pair<int,pair<int,int>>> hello_there;
        long long total_weight = 0;

        for(int i=0;i<edge;i++)
        {
            int from,to,weight;
            cin>>from>>to>>weight;
            hello_there.push_back({weight,{from,to}});
            total_weight +=weight;
        }

        long long mst = 0; int tryin = 0;

        sort(hello_there.begin(),hello_there.end());
        
        for(const auto& hi : hello_there)
        {
            int current_weight = hi.first;
            int current_from = hi.second.first;
            int current_to = hi.second.second;

            if(uf.unite(current_from,current_to))
            {
                mst+=current_weight;
                tryin++;
            }

            if(tryin==node-1)break;
        }
        cout<<total_weight-mst<<'\n';
    }
    return 0;
}
