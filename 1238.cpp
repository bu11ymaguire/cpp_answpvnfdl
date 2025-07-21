#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int get_distance(vector<vector<pair<int,int>>> &weight,int from, int to)
{
    if(from==to){return 0;}
    int node = weight.size()-1;
    vector<int> distance(node+1,INT_MAX);
    distance[from]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hello_there;
    hello_there.push({distance[from],from});
    while(!hello_there.empty())
    {
        int current_weight = hello_there.top().first;
        int current_node = hello_there.top().second;
        hello_there.pop();
        if(current_weight>distance[current_node])
        {
            continue;
        }
        for(int i=0;i<weight[current_node].size();i++)
        {
            int next_node = weight[current_node][i].first;
            int next_weight = weight[current_node][i].second;
            if(current_weight+next_weight<distance[next_node])
            {
                distance[next_node] = current_weight + next_weight;
                hello_there.push({distance[next_node],next_node});
            }
        }
    }
    return distance[to];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int node,way,goal;
    cin>>node>>way>>goal;
    vector<vector<pair<int,int>>> weight(node+1);
    for(int i = 0; i<way;i++)
    {
        int from,to,current_weight;
        cin>>from>>to>>current_weight;
        weight[from].push_back(make_pair(to,current_weight));
    }
    priority_queue<int> result;
    for(int i=1;i<=node;i++)
    {
        int output = get_distance(weight,i,goal) + get_distance(weight,goal,i);
        result.push(output);
    }
    cout<<result.top();
    return 0;
}
