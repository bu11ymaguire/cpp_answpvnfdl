#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    vector<bool> hello(100001,false);

    int from,to; cin>>from>>to;
    if(from==to){cout<<0;return 0;}

    queue<pair<int,int>> hi;
    hi.push({from,0});
    hello[from] = true;

    while(!hi.empty())
    {
        int node = hi.front().first;
        int distance = hi.front().second;
        hi.pop();

        distance++;

        int X[] ={node-1,node+1,2*node};

        for(const auto& N : X)
        {
            if(N<0||N>100000)continue;
            if(N==to){cout<<distance;return 0;}
            if(hello[N])continue;
            hello[N] = true;
            hi.push({N,distance});
        }
    }
    cout<<-1;
    return 0;
}
