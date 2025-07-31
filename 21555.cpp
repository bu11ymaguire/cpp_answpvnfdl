#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//무지성 문제 풀이의 폐해

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long k;

    cin>>n>>k;
    vector<long long> first(n+1,0);
    vector<long long> second(n+1,0);

    for(int i=1;i<=n;i++)
    {
        cin>>first[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>second[i];
    }

    vector<long long> first_result(n+1,0);
    vector<long long> second_result(n+1,0);

    first_result[1]=first[1];
    second_result[1]=second[1];

    for(int i=2;i<=n;i++)
    {
        first_result[i] = first[i] + min(first_result[i-1],second_result[i-1]+k);
        second_result[i] = second[i] + min(second_result[i-1],first_result[i-1]+k);
    }
    cout<<min(first_result[n],second_result[n]);
    return 0;
}
