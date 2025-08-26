#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin>>N;

    vector<int> hello(N);

    for(int i = 0; i <N;i++)
    {
        cin>>hello[i];
    }
    sort(hello.begin(),hello.end());

    int L = 0;
    int R = N-1;
    int best_L = L, best_R = R;

    long long best_sum = (long long)abs(hello[L]+hello[R]);

    while(L<R)
    {
        long long current_sum = (long long)(hello[L]+hello[R]);

        if(abs(current_sum)<best_sum)
        {
            best_sum = abs(current_sum);
            best_L = L; best_R = R;
        }

        if(current_sum==0)break;

        if(current_sum>0)R--;
        else L++;
    }

    cout<<hello[best_L]<<' '<<hello[best_R];
    return 0;
}
