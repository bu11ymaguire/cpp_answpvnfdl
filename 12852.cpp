#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> hello(1000001,0);
    vector<int> reverse(1000001,-1);
    hello[1]=0; //ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ

    for(int i =2;i<=1000000;i++)
    {
        hello[i] = hello[i-1]+1;
        reverse[i] = i - 1;
        if(i%2==0)
        {
            if(hello[i]>hello[i/2]+1) //경로 추적의 일관성을 위해 등호는 포함하지 않음!
            {
                hello[i] = hello[i/2] + 1;
                reverse[i] = i / 2;
            }
        }
        if(i%3==0)
        {
            if(hello[i]>hello[i/3]+1) //경로 추적의 일관성을 위해 등호는 포함하지 않음!
            {
                hello[i] = hello[i/3] + 1;
                reverse[i] = i / 3;
            }
        }
    }
    int N; cin>>N;
    cout<<hello[N]<<'\n';
    int tmp = N;
    while(tmp!=-1)
    {
        cout<<tmp<<' ';
        tmp = reverse[tmp];
    }
    return 0;
}
