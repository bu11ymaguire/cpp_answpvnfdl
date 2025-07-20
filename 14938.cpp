#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
//벡터 사이즈를 이용해 반복문을 만들떄는 범위 유의하기!!
int get_item(vector<int> item_info,vector<vector<pair<int,int>>> weight_info,int from, int limit)
{
    vector<int> distance(item_info.size()+1,INT_MAX);
    distance[from] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> renew_distance;
    renew_distance.push({0,from});
    while(!renew_distance.empty())
    {
        int now_weight = renew_distance.top().first;
        int now_node = renew_distance.top().second;
        renew_distance.pop();
        if(now_weight>distance[now_node]){continue;}
        for(int i=0;i<weight_info[now_node].size();i++)
        {
            int next_node = weight_info[now_node][i].first;
            int next_weight = weight_info[now_node][i].second;
            if(next_weight+now_weight<distance[next_node])
            {
                distance[next_node] = next_weight + now_weight;
                renew_distance.push({distance[next_node],next_node});
            }
        }
    }
    int Result=0; //초기화 꼭 하고
    for(int i=1;i<=item_info.size();i++)
    {
        if(distance[i]<=limit){
            Result+=item_info[i];
        }
    }
    return Result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int area,range,route;
    cin>>area>>range>>route;
    vector<int> item_value(area+1,0);
    for(int i=1;i<=area;i++)
    {
        cin>>item_value[i];
    }
    vector<vector<pair<int,int>>> weight_info(area+1);
    for(int i=0;i<route;i++)
    {
        int from,to,weight;
        cin>>from>>to>>weight;
        weight_info[from].push_back({to,weight});
        weight_info[to].push_back({from,weight});
    }

    priority_queue<int> hellothere;
    for(int i=1;i<=area;i++)
    {
        int result = get_item(item_value,weight_info,i,range);
        hellothere.push(result);
    }
    cout<<hellothere.top();
    return 0;
}
