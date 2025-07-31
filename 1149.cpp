#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    vector<long long> red(N+1,0);
    vector<long long> green(N+1,0);
    vector<long long> blue(N+1,0);

    for(int i=1;i<=N;i++)
    {
        cin>>red[i]>>green[i]>>blue[i];
    }

    vector<long long> result_red(N+1,0);
    vector<long long> result_green(N+1,0);
    vector<long long> result_blue(N+1,0);

    result_red[1] = red[1];
    result_green[1] = green[1];
    result_blue[1] = blue[1];

    for(int i=2;i<=N;i++)
    {
        result_red[i] = red[i] + min(result_green[i-1],result_blue[i-1]);
        result_green[i] = green[i] + min(result_blue[i-1],result_red[i-1]);
        result_blue[i] = blue[i] + min(result_red[i-1],result_green[i-1]);
    }

    priority_queue<long long,vector<long long>,greater<long long>> result;

    result.push(result_red[N]);
    result.push(result_blue[N]);
    result.push(result_green[N]);

    cout<<result.top();

    return 0;
}
