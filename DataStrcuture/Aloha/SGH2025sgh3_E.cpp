#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n; 
    cin>>n;
    if(n==1)
    {
        int tmp;
        cin>>tmp;
        cout<<1<<'\n'<<1;
        return 0;
    }

    vector<pair<int,int>> hello(n);

    for(int i = 0 ; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        hello[i] ={tmp,i+1};
    }
    
    sort(hello.begin(),hello.end());

    long long Max = 0;
    int trying = 0;

    vector<long long> total(n,0);

    for(int i = 1; i <= n; i++)
    {
        int max = hello[n-1].first;
        int min = hello[n-i].first;

        if(i==1)
        {
            total[i] = min;
        }else
        {
            total[i] = total[i-1] + min;
        }

        long long now = max + min + total[i];
        if(Max<now)
        {
            Max = now;
            trying = i;
        }
    }

    cout<<trying<<'\n';

    for(int i=1;i<=trying;i++)
    {
        cout<<hello[n-i].second<<' ';
    }
    
    return 0;
}
