#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class UnionFind
{
    private:
    vector<int> parents;
    vector<int> rank;
    public:
    UnionFind(int x)
    {
        parents.resize(x+1);
        rank.resize(x+1,1);
        for(int i = 0; i <= x;i++)
        {
            parents[i] = i;
        }
    }

    int find(int x)
    {
        if(parents[x]!=x){
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    int unite(int x,int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return rank[rootX];
        if(rank[rootX]>rank[rootY])
        {
            parents[rootY] = rootX;
            rank[rootX]+=rank[rootY];
            return rank[rootX];
        }else if(rank[rootX]<rank[rootY])
        {
            parents[rootX] = rootY;
            rank[rootY]+=rank[rootX];
            return rank[rootY];
        }else{
            parents[rootY] = rootX;
            rank[rootX]+=rank[rootY];
            return rank[rootX];
        }
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    for(int i = 0; i < N; i++)
    {
        int x = 1;
        unordered_map<string,int> check_friend;
        int n; cin>>n;
        UnionFind uf(2*n);
        for(int j = 0 ; j < n ; j++)
        {
            string input1,input2;
            cin>>input1>>input2;
            if(check_friend[input1]==0){
                check_friend[input1]=x;
                x++;
            }
            if(check_friend[input2]==0){
                check_friend[input2]=x;
                x++;
            }
            cout<<uf.unite(check_friend[input1],check_friend[input2])<<'\n';
        }
    }
    return 0;
}
