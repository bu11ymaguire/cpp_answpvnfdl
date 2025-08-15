#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node,edge; cin>>node>>edge;
    vector<vector<pair<int,int>>> hello(node+1);
    vector<long long> distance_node(node+1,LONG_LONG_MAX);
    distance_node[1] = 0;

    for(int i =0 ; i < edge; i++)
    {
        int from,to,weight;
        cin>>from>>to>>weight;
        hello[from].push_back({to,weight});
    }

    for(int i = 1; i <= node-1; i++)
    {
        for(int j = 1; j <=node;j++)
        {
            if(distance_node[j]!=LONG_LONG_MAX)
            {
                for(const auto& data : hello[j]){ //참조
                    int to = data.first;
                    int weight = data.second;
                    distance_node[to] = min(distance_node[to],distance_node[j] + weight); 
                }
            }
        }
    }

    bool is_negative = false;
    for(int j = 1; j <= node; j++){
    if(distance_node[j] != LONG_LONG_MAX)
    {
        for(const auto& data : hello[j]){
            int to = data.first;
            int weight = data.second;
            if(distance_node[j] + weight < distance_node[to])
            {
                is_negative = true;
                break;
            }
        }
        if(is_negative) break;
    }}

    if(is_negative){cout<<-1<<'\n';}
    else
    {
        for(int i = 2; i <= node; i++) 
        { 
        if(distance_node[i] == LONG_LONG_MAX) {
        cout << -1 << '\n';} else {
        cout << distance_node[i] << '\n';}}
    }

    return 0;
}
