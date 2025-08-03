#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,limit;
    cin>>n>>limit;
    vector<pair<int,int>> backpack(n+1,{0,0});

    for(int i=1;i<=n;i++)
    {
        int weight,value;
        cin>>weight>>value;
        backpack[i]={weight,value};
    }

    vector<int> output(limit+1,0);

    for(int i=1;i<=n;i++)
    {
        int now_weight = backpack[i].first;
        int now_value = backpack[i].second;

        for(int j= limit; j>=1; j--)
        {
          output[j] = max(output[j], output[j-now_weight] + now_value);
        }
          
    }

    cout<<output[n][limit];

    return 0;
}
