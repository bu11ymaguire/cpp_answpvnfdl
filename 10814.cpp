#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int,int>> welcome;
    unordered_map<int,string> info;
    int N,age;
    string name; 
    cin>>N;
    welcome.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>age>>name;
        info[i]=name;
        welcome[i]=(make_pair(age,i));
    }
    sort(welcome.begin(),welcome.end(),greater<pair<int,int>>());
    for(int i=N-1;i>=0;i--)
    {
        cout<<welcome[i].first<<' '<<info[welcome[i].second]<<'\n';
    }

    return 0;
}
