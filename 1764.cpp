#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;

    unordered_map<string,int> dm;
    string input;
    vector<string> dbj;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        dm[input]=1;
    }
    for(int i=0;i<m;i++){
        cin>>input;
        if(dm[input]==1){dbj.push_back(input);}
    }
    sort(dbj.begin(),dbj.end());
    cout<<dbj.size()<<'\n';
    for(int i=0;i<dbj.size();i++){
        cout<<dbj[i]<<'\n';
    }
    return 0;
}
