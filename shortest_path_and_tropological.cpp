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

void topologicalSort(ofstream&outFile)
{
  queue<int> hello;
  vector<int> world(adj_lists.size(),0);

  for(int i=0;i<adj_lists.size();i++)
  {
    for(int j=0;j<adj_lists[i].size();j++)
    {
      world[adj_lists[i][j].first]++;
    }
  }

  for(int i=0;i<world.size();i++)
  {
    if(world[i]==0)
    {
      hello.push(i);
    }
  }
  vector<int> topological;
  while(!hello.empty())
  {
    int current = hello.front();
    topological.push_back(current);
    hello.pop();
    for(int i=0;i<adj_lists[current].size();i++)
    {
      int to = adj_lists[current][i].first;
      world[to]--;
      if(world[to]==0)
      {
        hello.push(to);
      }
    }
  }
  if(topological.size()!=adj_lists.size()){
    outFile<<"Cycle Observed:\n";
  }
  else{
    for(int i=0;i<topological.size();i++)
  {
    if(i==topological.size()-1)
    {
      outFile<<topological[i]<<'\n';
    }else{
      outFile<<topological[i]<<' ';
    }
  }
  }
}

void van_dijk(int from,int to,ofstream &outFile)
{
  vector<int> haha(nodes,INT_MAX);
  haha[from] = 0;
  vector<int> ancesstor(nodes,-1);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> now_root;  //{node,distance}
  now_root.push({from,haha[from]});
  while(!now_root.empty())
  {
    int now_node = now_root.top().first;
    int now_weight = now_root.top().second;
    now_root.pop();

    if(now_weight>haha[now_node])
    {
      continue;
    }
    for(int i=0;i<adj_vector[now_node].size();i++)
    {
      
      int current_node = adj_vector[now_node][i].first;
      int current_weight = adj_vector[now_node][i].second;
      int sum = now_weight + current_weight;

      if(sum<haha[current_node])
      {
        haha[current_node] = sum;
        now_root.push({current_node,sum});
        ancesstor[current_node] = now_node;
      }
    }
  }

  if(haha[to]==INT_MAX)
  {
    outFile<<"This Node is Not Adjacent."<<endl;
    return;
  }

  stack<int> way;
  int now = to;

  while(now!=-1)
  {
    way.push(now);
    now = ancesstor[now];
  }

  while(!way.empty()){
    outFile<<way.top();
    way.pop();
  }
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

      case TOPOLOGICAL_SORT:
        if(g==nullptr)
        {
          cerr<<"topoLogical_Sort: Graphs is not generated"<<endl;
          exit(1);
        }

        iss >> ws;
        if(!iss.eof()){
          cerr<<"topoLogica_SORT:Invalid Input"<<endl;
          delete g;
          exit(1);
        }
        g->topologicalSort(outFile);
        break;

      case SHORTEST_PATH:
        if (!(iss >> u >> v)) 
        {
          cerr<<"SHORTEST_PATH: invalid input"<<endl;
          delete g;
          exit(1);
        }

        if(g==nullptr)
        {
          cerr<<"Graph is Empty."<<endl;
          delete g;
          exit(1);
        }

        if (u < 0 || u >= g->max_vertex || v < 0 || v >= g->max_vertex) {
             cerr << "SHORTEST_PATH: Invalid input - vertex index out of bounds" << endl;
             exit(1);
        }
        g->shortest_path(u,v,outFile);
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
