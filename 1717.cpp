#include<iostream>
#include<vector>
using namespace std;

class UnionFind{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0 ; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY)
        {
            if(rank[rootX]>rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if(rank[rootY]>rank[rootX])
            {
                parent[rootX] = rootY;
            }else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    bool is_union(int x,int y)
    {
        return find(x)==find(y);
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;
    UnionFind hello(n+1);
    for(int i =0; i <m; i++)
    {
        int question;
        cin>>question;
        if(question==0){
            int a,b;cin>>a>>b;
            hello.unite(a,b);
        }
        else if(question==1){
            int a,b;
            cin>>a>>b;
            if(hello.is_union(a,b)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
