#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<int> wine(N+1,0);
    for(int i=1;i<=N;i++)
    {
        cin>>wine[i];
    }

    vector<int> result(N+1,0);
    result[1] = wine[1];
    result[2] = result[1] + wine[2];
    for(int i=3;i<=N;i++)
    {
        priority_queue<int> temporary;
        temporary.push(result[i-1]);
        temporary.push(result[i-2]+wine[i]);
        temporary.push(result[i-3]+wine[i-1]+wine[i]);
        result[i] = temporary.top(); //무지성 점화식이 항상 큰 값을 보장하지는 않는다!
    }

    cout<<result[N];

    return 0;
}
