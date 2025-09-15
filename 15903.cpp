#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,m; cin >> N >> m; 
    vector<long long> hello(N); //while을 반복하다보면 원소들도 값이 커저서 오버플로우가 생길 수 있음!

    for(int i = 0; i < N ; i++)
    {
        cin >> hello[i];
    }

    while(m--)
    {
        sort(hello.begin(),hello.end());
        long long one = hello[0];
        long long two = hello[1];
        hello[0] = one + two;
        hello[1] = hello[0];
    }

    long long result = 0;

    for(const auto& hi : hello){
        result += hi;
    }

    cout << result;

    return 0;
}
