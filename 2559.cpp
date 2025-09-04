#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K; cin>>N>>K;
    vector<int> hello(N);

    for(int i = 0; i < N; i++)
    {
        cin>>hello[i];
    }
    long long now_sum = 0;
    int L = 0;
    int R = K-1;
    for(int i=L; i<=R;i++)
    {
        now_sum += hello[i];
    }
    R++;
    /*
    long long result = 0;
    result = max(result, now_sum); 으로 초기화 할 경우 hello 안의 원소가 모두 음수일때의 결과값이 제대로 출력되지 않을 수 있음!
    */
    long long result = now_sum; //처음은 now_sum 으로 초기화해야 오류가 안남!
    while(R<=N-1)
    {
        now_sum -= hello[L];
        L++;
        now_sum += hello[R];
        R++;
        result = max(result,now_sum);
    }
    cout<<result;
    return 0;
}
