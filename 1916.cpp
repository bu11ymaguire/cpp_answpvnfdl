#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int vertice, edges;
    cin>>vertice>>edges;
    vector<vector<pair<int,int>>> hello(vertice+1); //{To,Weight}
    for(int i=0;i<edges;i++)
    {
        int tmp_from,tmp_to, tmp_weight;
        cin>>tmp_from>>tmp_to>>tmp_weight;
        hello[tmp_from].push_back({tmp_to,tmp_weight});
    }
    int from,to;
    cin>>from>>to;
    vector<int> hi(vertice+1,INT_MAX);
    hi[from]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> distance; //weight, to 순서쌍
    distance.push(make_pair(hi[from],from));
    while(!distance.empty())
    {
        int current_node = distance.top().second;
        int current_distance = distance.top().first;
        distance.pop();
        if(current_distance>hi[current_node]){continue;}

        for(int i =0 ;i<hello[current_node].size() ;i++)
        {
            int next_node = hello[current_node][i].first;
            int next_weight = hello[current_node][i].second;
            int total_distance = next_weight + current_distance;
            if(total_distance<hi[next_node])
            {
                hi[next_node] = total_distance;
                distance.push(make_pair(total_distance,next_node));
            }
        }
    }
    cout<<hi[to];
    return 0;
}
