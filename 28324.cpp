#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin>>N;
    vector<int> input(N);

    for(int i = 0 ; i < N ; i++)
    {
        cin>>input[i];
    }

    long long sum = 1;
    int before=1;

    for(int i = N-1; i>=0; i--) //거꾸로 돌면 생각하기 편해!
    {
        if(i==N-1)
        {
            continue;
        }
        else
        {
            int now = input[i];
            if(now<=before)
            {
                before = now;
                sum+= before;
            }else
            {
                before++;
                sum+= before;
            }
        }
    }
    cout<<sum;
    return 0;
}
