#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cctype>
using namespace std;

bool isInteger(const string& str){
    if (str.empty()) return false;
    return std::all_of(str.begin(), str.end(), [](char c) { return std::isdigit(c); });
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, int> dictation;
    int N,P;
    cin>>N>>P;
    vector<string> dict(N+1);
    string input;
    for(int i=1;i<=N;i++)
    {
        cin>>input;
        dict[i]=input;
        dictation[input]=i;
    }
    for(int i=0;i<P;i++){
        cin>>input;
        if(isInteger(input)){
            cout<<dict[stoi(input)]<<'\n';
        }else{
            cout<<dictation[input]<<'\n';
        }
    }
    return 0;
}
