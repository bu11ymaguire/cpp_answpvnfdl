#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
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
        rank.resize(x+1,0);
        for(int i = 0; i <= x; i++)
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
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    vector<pair<double,double>> hello(N);

    for(int i = 0; i <N; i++)
    {
        double X,Y; 
        cin>>X>>Y;
        hello[i] = {X,Y};
    }

    vector<pair<double,pair<int,int>>> distance_info;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i==j) continue;
            double distance = sqrt((hello[i].first-hello[j].first)*(hello[i].first-hello[j].first)+(hello[i].second-hello[j].second)*(hello[i].second-hello[j].second));
            distance_info.push_back({distance,{i,j}});
        }
    }

    sort(distance_info.begin(),distance_info.end());
    int trying = 0;
    double fee = 0;

    UnionFind uf(N);

    for(const auto& hi : distance_info)
    {
        int x = hi.second.first;
        int y = hi.second.second;
        if(uf.unite(x,y))
        {
            fee += hi.first;
            trying++;
        }
        if(trying==N-1) break;
    }
    cout << fixed << setprecision(2) << fee << endl;
    return 0;
}
