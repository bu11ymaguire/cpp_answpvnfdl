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
    int find(int x) //단순히 해당 원소가 어디에 속해 있는지를 출력하는 것이 아닌, 해당 원소가 속해있는 집합의 루트 노드를 출력 -> 루트 노드가 같으면 같은 집합에 소속되어 있음.
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
