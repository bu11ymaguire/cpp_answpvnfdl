#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    if(N==1){ //1개면 굳이 비교 X
        int tmp; cin >> tmp;
        cout << 0;
        return 0;
    }
    priority_queue<long long,vector<long long>,greater<long long>> pq;

    while(N--)
    {
        long long tmp; cin >> tmp;
        pq.push(tmp);
    }

    long long sum = 0;
    while(pq.size()>1)
    {
        long long one = pq.top();
        pq.pop();
        long long two = pq.top();
        pq.pop();
        sum += (one + two);
        pq.push(one + two);
    }

    cout << sum;
    return 0;
}
