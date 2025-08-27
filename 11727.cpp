#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<long long> hello(1001,0);
    hello[1] = 1;
    hello[2] = 3;
    for(int i=3;i<=1000;i++)
    {
        hello[i] = (hello[i-1] + 2 * hello[i-2])%10007; //문제를 조금 꼼꼼히... 
    }
    int N;cin>>N;
    cout<<hello[N];
    return 0;
}
