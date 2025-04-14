#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    unordered_map<string,string> pword; //pair와 vector를 이용하면 시간복잡도가 O(N*M)이니 unordered_map을 사용하자
    for(int i=0;i<n;i++){
        string site,pass;
        cin>>site>>pass;
        pword[site]=pass;
    }
    for(int i=0;i<m;i++){
        string siu;
        cin>>siu;
        cout<<pword[siu]<<'\n';
    }
    return 0;
}
