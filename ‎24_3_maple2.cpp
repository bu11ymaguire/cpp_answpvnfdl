#include<bits/stdc++.h>
using namespace std;
//https://project-ps.com/problem/131

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;

    vector<int> hello(N+1,0);

    for(int i = 1; i<=N; i++)
    {
        cin >> hello[i];
    }

    int tmp; cin >> tmp;
    stack<int> hellothere;
    hellothere.push(tmp);
    while(true)
    {
        int now = hellothere.top();
        int next = hello[now];
        if(now==next)break;
        hellothere.push(next);
    }
    if(hellothere.size()==1)
    {
        cout <<"Eh?";
    }else
    {
        while(!hellothere.empty())
        {
            cout <<  hellothere.top() <<' ';
            hellothere.pop();
        }
        cout <<'\n';
    }


    return 0;
}
