#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

bool my_order(pair<string,int> a, pair<string,int> b){
    if(a.second != b.second){
        return a.second>b.second;
    } if(a.first.length()!= b.first.length()){
        return a.first.length() > b.first.length();
    }
    return a.first < b.first;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<string> hello;
    unordered_map<string,int> check_insert;
    string input;

    for(int i=0;i<n;i++){
        cin>>input;
        if(input.length()<m)
        {
            continue;
        }
        if(check_insert[input]==0){
            hello.push_back(input);
        }
        check_insert[input]++;
    }

    vector<pair<string,int>> world;

    for(int i=0;i<hello.size();i++){
        world.push_back({hello[i],check_insert[hello[i]]});
    }

    sort(world.begin(),world.end(),my_order);

    for(int i=0;i<world.size();i++){
        cout<<world[i].first<<'\n';
    }

    return 0;
}
