#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//MST 문제는 노드간 연결 정보를 입력 받은 후, UnionFind로 노드들의 연결 여부를 확인 후 이후 연산을 수행한다. 

class UnionFind //간선간 연결 정보 확인
{
    private:
    vector<int> parent;
    vector<int> rank;

    public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0; i <= n; i++){
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
        if(rootX == rootY) return false; //이미 같은 집합에 속하므로 unite 실패
        if(rootX != rootY)
        {
            if(rank[rootX]>rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if(rank[rootY]>rank[rootX])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
        return true;// unite 완료.
    }

    bool is_union (int x, int y)
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

    vector<pair<int,pair<int,int>>> Edge;

    for(int i = 0; i < edge; i++)
    {
        int from,to,weight;
        cin>>from>>to>>weight;
        Edge.push_back({weight,{from,to}});
    }

    sort(Edge.begin(),Edge.end()); //기본적으로 sort는 pair의 first를 오름차순.
    UnionFind uf(node);
    long long total = 0;
    int trying = 0;

    //MST는 weight 오름차순 정렬된 Edge를 순회하면서 모든 노드들의 연결 정보를 파악한다. 이때, 두 노드간 연결이 형성되지 않은 경우, total 값에 가중치를 넣은 후 연산 횟수를 1회 더한다. 
    for(const auto& hello:Edge)
    {
        int now_weight = hello.first;
        int now_from = (hello.second).first;
        int now_to = (hello.second).second;
        if((uf.unite(now_from,now_to))){
            total+=now_weight;
            trying++;
        }
        if(trying==node-1) break;
    }

    cout<<total;
    return 0;
}
