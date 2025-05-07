#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,a,b;
    cin>>N;
    vector<pair<int,int>> hello;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        hello.push_back(make_pair(b,a));
    }
    sort(hello.begin(),hello.end(),greater<pair<int,int>>());
    for(int i=N-1;i>=0;i--){
        cout<<hello[i].second<<' '<<hello[i].first<<'\n';
    }

    return 0;
}
