#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;
    cin>>N;
    vector<long long> meter(N-1);
    vector<long long> hello(N);

    for(int i=0;i<N-1;i++)
    {
        cin>>meter[i];
    }

    for(int i=0;i<N;i++)
    {
        cin>>hello[i];
    }

    long long now_oil = hello[0];
    long long cost = hello[0] * meter[0];

    for(int i=1;i<N-1;i++)
    {
        now_oil = min(now_oil, hello[i]);
        cost += now_oil * meter[i];
    }
    cout<<cost;
    return 0;
}
