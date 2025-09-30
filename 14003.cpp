#include<bits/stdc++.h>
using namespace std;
//0 - base 유의! && iterator는 iterator끼리 연산 후 형 변환!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;

    vector<int> in(N); vector<int> hellothere;
    vector<int> info(N,0);

    for(int i = 0; i < N ; i++)
    {
        cin >> in[i];    
    }
    hellothere.push_back(in[0]);

    for(int i = 1; i < N ; i++)
    {
        if(in[i]>hellothere.back())
        {
            hellothere.push_back(in[i]);
            info[i] = hellothere.size() - 1;
        }
        else
        {
            auto it = lower_bound(hellothere.begin(),hellothere.end(),in[i]);
            int index = it - hellothere.begin();
            hellothere[index] = in[i];
            info[i] = index;
        }
    }

    int target = hellothere.size()-1;
    stack<int> good;

    for(int i = N-1; i >=0; i--)
    {
        if(info[i]==target)
        {
            good.push(i);
            target--;
        }
    }

    cout << good.size() <<'\n';
    while(!good.empty())
    {
        cout << in[good.top()]<< ' ';
        good.pop();
    }

    return 0;
}
