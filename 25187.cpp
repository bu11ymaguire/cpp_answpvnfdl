#include<bits/stdc++.h>
using namespace std;

class WaterFind
{
    private:
    vector<int> parent;
    vector<pair<long long,long long>> water;
    vector<long long> rank;

    public:
    WaterFind(int n)
    {
        parent.resize(n+1,0);
        water.resize(n+1,{0,0});
        rank.resize(n+1,0);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    void set_water(int n, int w)
    {
        if(w==0)
        {
            water[n].first++;
        }else
        {
            water[n].second++;
        }
    }

    int find(int n)
    {
        if(n!=parent[n])
        {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA==rootB)
        {
            return;
        }

        if(rank[rootA]>rank[rootB])
        {
            parent[rootB] = rootA;
            water[rootA].first += water[rootB].first;
            water[rootA].second += water[rootB].second;
        }else if(rank[rootA]<rank[rootB])
        {
            parent[rootA] = rootB;
            water[rootB].first += water[rootA].first;
            water[rootB].second += water[rootA].second;
        }else{ //랭크가 같은 경우.
            parent[rootB] = rootA;
            rank[rootA]++;
            water[rootA].first += water[rootB].first;
            water[rootA].second += water[rootB].second;
        }
        return;
    }

    void print(int n){
        int root = find(n); //!
        if(water[root].first>=water[root].second){ //조건을 좀 잘 읽어라.
            cout << 0 <<'\n';
        }else{
            cout << 1 << '\n';
        }
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tank, pipe, visit;
    cin >> tank >> pipe >> visit;

    WaterFind WF(tank);
    for(int i = 1; i <= tank ; i++)
    {
        int w; cin >> w;
        WF.set_water(i,w);
    }

    while(pipe--)
    {
        int a,b;
        cin >> a >>b;
        WF.unite(a,b);
    }

    while(visit--)
    {
        int vist;
        cin >> vist;
        WF.print(vist);
    }
    return 0;
}
