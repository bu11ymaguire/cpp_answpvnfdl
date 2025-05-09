#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

bool make_rule(const string& a, const string&b )
{
    if(a.length() !=b.length())
    {
        return a.length()<b.length();
    }
    return a<b;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string,int> duplicated;
    vector<string> haha;
    string hello;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>hello;
        if(duplicated[hello]!=1){
            duplicated[hello]=1;
            haha.push_back(hello);
        }
    }
    sort(haha.begin(),haha.end(),make_rule);
    for(int i=0;i<haha.size();i++){
        cout<<haha[i]<<'\n';
    }
    return 0;
}
