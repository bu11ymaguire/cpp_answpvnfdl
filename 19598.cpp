#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<pair<long long,long long>> hello_there(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin >> hello_there[i].first >> hello_there[i].second;
    }

    sort(hello_there.begin(),hello_there.end());

    priority_queue<long long,vector<long long>,greater<long long>> pq;

    for(const auto& obiwan : hello_there)
    {
        long long start = obiwan.first;
        long long end = obiwan.second;

        if(!pq.empty()&&pq.top()<=start) //ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 
        {
            pq.pop();
        }

        pq.push(end);
    }

    cout << pq.size() <<'\n';
    return 0;
}
