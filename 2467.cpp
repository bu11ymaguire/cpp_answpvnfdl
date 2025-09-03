#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<int> hello(N);
    
    for( int i =0 ; i <N ;i++)
    {
       cin>>hello[i];
    }

    sort(hello.begin(),hello.end());

    long long sum = LLONG_MAX;
    int L = 0;
    int R = N-1;
    int best_L = L;
    int best_R = R;
    while(L<R)
    {
        long long now = hello[L] + hello[R];
        if(abs(now)<sum)
        {
            best_L = L;
            best_R = R;
            sum = abs(now);
        }
        if(now==0)break;
        if(now>0)R--;
        if(now<0)L++;
    }
    cout<<hello[best_L]<<' '<<hello[best_R];    
    return 0;
}
