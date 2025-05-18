#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int node,root;
    cin>>node>>root;
    vector<vector<pair<int,int>>> graph(node);
    int start;
    cin>>start;
    start--;

    int from,to,weight;
    for(int i=0;i<root;i++)
    {
        cin>>from>>to>>weight;
        graph[from-1].push_back(make_pair(to-1,weight));
    }
    vector<int> dijk(node,INT_MAX);
    dijk[start]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> NDE;
    NDE.push({dijk[start],start});
    while(!NDE.empty())
    {
        int current_distance = NDE.top().first;
        int current_node = NDE.top().second;
        NDE.pop();

        if(current_distance>dijk[current_node]){continue;}

        for(int i=0;i<graph[current_node].size();i++)
        {
            int now_node = graph[current_node][i].first;
            int now_distance = graph[current_node][i].second;
            int new_distance = now_distance + current_distance;

            if(new_distance<dijk[now_node]){
                dijk[now_node] = new_distance;
                NDE.push({new_distance,now_node});
            }
        }
    }
    for(int i=0;i<dijk.size();i++)
    {
        if(dijk[i]==INT_MAX){
            cout<<"INF\n";
        }else{
            cout<<dijk[i]<<'\n';
        }
    }
    return 0;
}
