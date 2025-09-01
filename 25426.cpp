#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    long long sum = 0;

    priority_queue<int> input;

    while(N--)
    {
        int a,b;
        cin>>a>>b;
        sum+=b; //b는 상수항이므로 그냥 바로 더해주면 됨!
        input.push(a);
    }

    while(!input.empty())
    {
        sum+= input.top() * input.size();
        input.pop();
    }

    cout<<sum;

    return 0;
}
