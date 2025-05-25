#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> input;
    vector<int> check;
    unordered_map<int,int> validated;
    unordered_map<int,int> output;
    int n,tmp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        if(validated[tmp]==0)
        {
            validated[tmp]=1;
            check.push_back(tmp);
        }
        input.push_back(tmp);
    }
    sort(check.begin(),check.end());
    for(int i=0;i<check.size();i++)
    {
        output[check[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        cout<<output[input[i]]<<' ';
    }
    return 0;
}
