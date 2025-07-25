#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<int> hello(N);

    for(int i = 0 ; i<N ; i++)
    {
        cin>>hello[i];
    }

    vector<int> dp(N,1);
    vector<int> root(N,-1);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(hello[j]<hello[i])
            {
                if(dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    root[i]=j;
                }
            }
        }
    }

    int length = 0;
    int end_index = 0;
    for(int i=0;i<N;i++)
    {
        if(length<dp[i])
        {
            length = dp[i];
            end_index = i;
        }
    }

    cout<<length<<'\n';
    stack<int> route;
    while(end_index!=-1)
    {
        route.push(end_index);
        end_index = root[end_index];
    }
    while(!route.empty()){
        cout<<hello[route.top()]<<' ';
        route.pop();
    }

    return 0;
}
