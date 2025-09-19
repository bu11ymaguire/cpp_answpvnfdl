#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
    private:
    vector<int> parents;
    vector<int> rank;

    public:
    UnionFind(int n)
    {
        parents.resize(n);
        rank.resize(n,0);
        for(int i =0; i <n ;i++)
        {
            parents[i] = i;
        }
    }

    int find(int x)
    {
        if(x !=parents[x])
        {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX==rootY) //두 함수가 이미 연결되어 있다면, 이는 사이클 존재!
        {
            return false;
        }
        else
        {
            if(rank[rootX]>rank[rootY])
            {
                parents[rootY] = rootX;
            }
            else if(rank[rootX]<rank[rootY])
            {
                parents[rootX] = rootY;
            }
            else
            {
                parents[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, m;
    cin >> N >> m;
    UnionFind uf(N);
    int alpha = 0;
    bool cycle = false;
    while(m--)
    {
        alpha++;
        int a,b;
        cin >> a >>b;
        if(uf.unite(a,b))
        {
            continue;
        }else
        {
            cycle = true;
            break;
        }
    }
    if(cycle){
        cout << alpha;
    }else{
        cout << 0;
    }
    return 0;
}
