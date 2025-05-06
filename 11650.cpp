#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int,int>> hello;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        hello.push_back(make_pair(a,b));
    }
    sort(hello.begin(),hello.end(),greater<pair<int,int>>());
    for(int i=n-1;i>=0;i--)
    {
        cout<<hello[i].first<<' '<<hello[i].second<<'\n';
    }

    return 0;
}
