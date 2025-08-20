#include<iostream>
#include<vector>
using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n){
      parent.resize(n+1);
      rank.resize(n+1,0);
      
      for(int i = 0 ; i <= n; i++ ){
        parent[i] = i ;
      }
    }
    int find(int x) { //단순히 해당 원소가 어디에 속해 있는지를 출력하는 것이 아닌, 해당 원소가 속해있는 집합의 루트 노드를 출력 -> 루트 노드가 같으면 같은 집합에 소속되어 있음.
      if (parent[x] != x) {
        parent[x] = find(parent[x]);
      }
      return parent[x];
    }
    void unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
      
        if (rootX != rootY){
          if (rank[rootX] < root[rootY]) {
              parent[rootX] = rootY;
          } else if (rank[rootX] > rank[rootY]) {
              parent[rootY] = rootX;
          } else {
              parent[rootY] = rootX;
              rank[rootX]++;
          }
        }
    }
    bool isConnected(int x, int y){
        return (find(x) == find(y));
    }

};
