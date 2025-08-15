#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;cin>>test;

    for(int i = 0 ; i < test; i++)
    {
        int node,edge,warmhole;
        cin>>node>>edge>>warmhole;
        vector<vector<pair<int,int>>> node_info(node+1);

        for(int j = 0 ; j < edge; j++)
        {
            int from,to,weight;
            cin>>from>>to>>weight;
            node_info[from].push_back({to,weight});
            node_info[to].push_back({from,weight}); //그래프 방향 X -> 양방향 고려!
        }

        for(int j = 0 ; j < warmhole; j++)
        {
            int from,to,warm;
            cin>>from>>to>>warm;
            warm *=-1;
            node_info[from].push_back({to,warm});
        }

        vector<long long> distance(node+1,0);

        for(int k = 0 ; k < node-1; k++) //벨만 포드의 시간복잡도는 O(VE)
        {
            for(int j=1; j<=node;j++)
        {
            if(distance[j]!=LONG_LONG_MAX)
            {
                for(const auto& hello:node_info[j])
                {
                    int to = hello.first; int weight = hello.second;
                    distance[to] = min(distance[to],distance[j]+weight);
                }
            }
        }
        }

        bool is_negative = false;
        for(int j=1; j <=node;j++)
        {
           for(const auto& hello:node_info[j])
           {
            int to = hello.first;
            int weight = hello.second;
            if(distance[j] + weight < distance[to]){
                is_negative = true;
                break;
            }
           }
        }

        if(is_negative)cout<<"YES\n";
        else{cout<<"NO\n";}
    }
    return 0;
}
