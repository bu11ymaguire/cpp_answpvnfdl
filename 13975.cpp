#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;
    cin>>N;
    for(int i = 0 ; i < N ; i++)
    {
        int n;
        cin>>n;
        priority_queue<long long,vector<long long>,greater<long long>> hello;
        for(int j = 0; j < n; j++){
            int tmp;
            cin>>tmp;
            hello.push(tmp);
        }
        long long result = 0;
        while(hello.size()>1)
        {
            long long first = hello.top();hello.pop();
            long long second = hello.top();hello.pop();
            result += (first+second);
            hello.push(first+second);        
        }
        cout<<result<<'\n';
    } //기존의 오름차순 정렬 & stack 사용을 -> pq(오름차순)의 크기가 1이 될때까지 반복
    return 0;
}
