#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >>N;

    if(N==1)
    {
        cout<<0;
        return 0;
    }

    bool input_prime = false;
    vector<int> hello;
    for(int i =2; i <=N;i++)
    {
        if(i==2)
        {
            hello.push_back(i);
        }
        else
        {
            if(i%2==0)continue;
            bool check_prime = true;

            for(const auto& haha: hello)
            {
                if(haha*haha >i) break;

                if(i%haha==0)
                {
                    check_prime = false;
                    break;
                }
            }

            if(check_prime) hello.push_back(i);
        }
    }

    int trying = 0;
    int L = 0;
    int R = 0;
    long long sum = 0;
    
    while(R<hello.size())
    {
        sum+= hello[R];
        while(sum>=N&&L<=R) //sum이 N보다 큰 경우 작은 숫자부터 하나씩 뺀다. 이때 sum이 N보다 작거나 L이 R보다 작아지지 않는 경우 반복문은 종료한다.
        {
            if(sum==N)trying++;
            sum -= hello[L];
            L++;
        }
        R++;
    }

    cout<<trying;
    return 0;
}
