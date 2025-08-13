#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> hello(N);

    for(int i = 0 ; i < N ; i++)
    {
        cin>>hello[i];
    }

    sort(hello.begin(),hello.end());
    long long sum = hello[2]-hello[0];

    for(int i = 4; i < N ; i+=2)
    {
        sum += hello[i] - hello[i-1];
    }

    long long ans = sum;

    //점화식 잘 세우기. hello[2] - hello[0] -> hello[4] - hello[2]로 교체에 따른 주변 교통 정리
    for(int i = 2; i <N-2 ; i+=2 )
    {
        sum -= (hello[i] - hello[i-2]);
        sum -= (hello[i+2]- hello[i+1]);
        sum += (hello[i-1] - hello[i-2]);
        sum += (hello[i+2] - hello[i]);
        ans = min(ans,sum);
    }

    cout<<ans;
    return 0;
}
