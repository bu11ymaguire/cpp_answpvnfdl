#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<long long,pair<int,int>>> fibo(41,{0,{0,0}}); //{피보나치 값,{fibo(0) 언급도르, fibo(1) 언급도르}}
    fibo[0]={0,{1,0}};
    fibo[1]={1,{0,1}};
    for(int i=2;i<=40;i++)
    {
        long long value_first = fibo[i-2].first;
        int zero_first = fibo[i-2].second.first;
        int one_first = fibo[i-2].second.second;

        long long value_second = fibo[i-1].first;
        int zero_second = fibo[i-1].second.first;
        int one_second = fibo[i-1].second.second;

        fibo[i]={value_first+value_second,{zero_first+zero_second,one_first+one_second}};
    }

    int question; cin>>question;

    for(int i=1;i<=question;i++)
    {
        int q; cin>>q;
        cout<<fibo[q].second.first<<' '<<fibo[q].second.second<<'\n';
    }
    return 0;
}
