#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int,int> haha;
    vector<int> hello;
    int n,tmp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        if(haha[tmp]!=1){
            haha[tmp]=1;
            hello.push_back(tmp);
        }
    }
    sort(hello.begin(),hello.end());

    for(int i=0;i<hello.size();i++)
    {
        cout<<hello[i]<<' ';
    }

    return 0;
}
