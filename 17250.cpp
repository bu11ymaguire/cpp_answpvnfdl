#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
    private:
    vector<long long> rank;
    vector<int> parent;

    public:
    UnionFind(int n)
    {
        parent.resize(n+1,0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        rank.resize(n+1,0);
    }

    int find(int n){
        if(n!=parent[n])
        {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }
    
    void set_rank(int a, long long b)
    {
        rank[a] = b;
    }

    void unite(int a,int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA==rootB)
        {
            cout << rank[rootA] <<'\n';
            return;
        }

        if(rank[rootA]>=rank[rootB])
        {
            rank[rootA]+=rank[rootB];
            parent[rootB] = rootA;
            cout << rank[rootA] << '\n';
        }
        else
        {
            rank[rootB]+=rank[rootA];
            parent[rootA] = rootB;
            cout << rank[rootB] << '\n';
        }
        return;
    } 
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,m;
    cin >> N >> m;
    UnionFind uf(N);
    for(int i = 1 ;i <= N; i++)
    {
        long long value;
        cin >> value;
        uf.set_rank(i,value);
    }
    while(m--)
    {
        int a, b;
        cin >> a >>b;
        uf.unite(a,b);
    }
    return 0;
}
