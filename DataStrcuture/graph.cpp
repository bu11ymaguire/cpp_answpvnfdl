// Practice 10. Graph Representation
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue> // BFS
#include <sstream>
#include <stack> // DFS
#include <tuple>
#include <vector>
using namespace std;
const char CONSTRUCT = 'C';
const char IS_ADJACENT = 'I';
const char GET_NEIGHBORS = 'N';
const char BFS = 'B';
const char DFS = 'D';
const char REACHABLITY = 'R';
const char TOPOLOGICAL_SORT = 'T';
const char SHORTEST_PATH = 'S';

class Graph {
public:
vector<vector<pair<int,int>>> adj_lists;
int max_vertex;
int edges;
Graph(int max_vertex,int edges)
{
  this->max_vertex = max_vertex;
  this->edges = edges;
  adj_lists.resize(this->max_vertex);
}
void add_Adj(int From,int To,int Weight)
{
  if(From>=0&&To<max_vertex&&From<max_vertex&&To>=0)
  {
    adj_lists[From].push_back(make_pair(To,Weight));
  }
}

bool is_Adjacent(int From,int To)
{
  if(From<0||To<0||From>=max_vertex||To>=max_vertex){
    return false;
  }

  for(int i=0;i<adj_lists[From].size();i++){
    if(adj_lists[From][i].first==To){
      return true;
    }
  }
  return false;
}

void getNeighbors(int vertex,ofstream& outFile){
  if(vertex>=0&&vertex<max_vertex){
    for(int i=0;i<adj_lists[vertex].size();i++)
    {
      outFile<<adj_lists[vertex][i].first<<" ";
    }
  }
  outFile<<endl;
}

};

 
int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr<<"Correct usage: [exe] [input] [output]"<<endl;
    exit(1);
  }
  Graph* g = nullptr;
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string line;
  while (getline(inFile, line))
  {
    char op = line[0];
    istringstream iss(line.substr(1));
    int u, v, wgt, nVertices, nEdges, cnt;
    vector<tuple<int, int, int>> data;
    vector<int> p, nbrs;

    switch(op)
    {

      case CONSTRUCT:
        if (!(iss >> nVertices >> nEdges)) 
        {
          cerr<<"CONSTRUCT: invalid input"<<endl;
          delete g;
          exit(1);
        }

        if(g!=nullptr)
        {
          cerr<<"CONSTRUCT: Graph is already Generated"<<endl;
          delete g;
          exit(1);
        }

        g = new Graph(nVertices,nEdges);
        for(int i=0;i<nEdges;i++)
        {
          string get_edge;

          if(!getline(inFile,get_edge)){
            cerr<<"CONSTRUCT: invalid input"<<endl;
            delete g;
            exit(1);
          }

          istringstream get_member(get_edge);
          int from,to,weight;
          if(!(get_member>>from>>to>>weight))
          {
            cerr<<"CONSTRUCT: invalid input"<<endl;
            delete g;
            exit(1);
          }

          if(from>=0&&to<nVertices&&from<nVertices&&to>=0){
            g->add_Adj(from,to,weight);
          }else{
            cerr<<"CONSTRUCT: invalid input"<<endl;
            delete g;
            exit(1);
          }

        }
        break;

      case IS_ADJACENT:
        if (!(iss >> u >> v)) 
        {
          cerr<<"isAdjacent: invalid input"<<endl;
          delete g;
          exit(1);
        }

        if(g==nullptr)
        {
          cerr<<"isAdjacent: Graphs is not generated"<<endl;
          delete g;
          exit(1);
        }

        outFile<<u<<" "<<v;
        if(g->is_Adjacent(u,v)){
          outFile<<" T"<<endl;
        }
        else{
          outFile<<" F"<<endl;
        }
        break;

      case GET_NEIGHBORS:
        if (!(iss >> u)) {
          cerr<<"getNeighbors: invalid input"<<endl;
          delete g;
          exit(1);
        }
        if (g==nullptr)
        {
          cerr<<"getNeighbors: Graphs is not generated"<<endl;
          delete g;
          exit(1);
        }
        g->getNeighbors(u,outFile);
        break;

      default:
        cerr<<"Undefined operator"<<endl;
        delete g;
        exit(1);
    }
  }
  delete g;
  outFile.close();
  inFile.close();
}
