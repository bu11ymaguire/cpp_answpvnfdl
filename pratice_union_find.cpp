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
    int find(int x) {
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
