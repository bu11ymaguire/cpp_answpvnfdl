#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int node,route;
    cin>>node>>route;
    vector<vector<pair<int,int>>> hello(node+1);
    for(int i = 0 ; i <route ; i++)
    {
        
        int from,to,weight;
        cin>>from>>to>>weight;
        hello[from].push_back({to,weight});
    }

    vector<vector<long long>> distance(node+1,vector<long long>(node+1,LONG_LONG_MAX));

    for(int i = 1; i <=node; i++)
    {
        int now_node = i;
        distance[i][i] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hello_there;
        hello_there.push({distance[i][i],i});

        while(!hello_there.empty())
        {
            int now_weight = hello_there.top().first;
            int now_node = hello_there.top().second;
            hello_there.pop();
            if(distance[i][now_node]<now_weight){continue;}
            for(const auto& hihi : hello[now_node])
            {
                int next_weight = hihi.second;
                int next_node = hihi.first;
                if(distance[i][next_node]>now_weight + next_weight)
                {
                    distance[i][next_node] = now_weight + next_weight;
                    hello_there.push({now_weight+next_weight,next_node});
                }
            }
        }
    }

    for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <= node; j++)
        {
            if(distance[i][j]==LONG_LONG_MAX){cout<<0<<' ';}
            else{cout<<distance[i][j]<<' ';}
        }
        cout<<'\n';
    }

    return 0;
}
