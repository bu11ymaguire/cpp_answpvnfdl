#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;cin>>N;

    vector<pair<int,int>> hello(N);
    for(int i = 0 ; i < N; i++)
    {
        int one,two;
        cin>>one>>two;
        hello[i] = {one,two};
    }

    
    int current_min = 0; //최솟값 초기화
    int ans = 1; //기본적으로 1개는 존재한다.(구역의 개수 = 칸막이 + 1 이므로)
    
    for(auto now: hello)
    {
        int now_min = now.first;
        int now_max = now.second;

        if(current_min>now_max) //새로운 분할 필요
        {
            ans++; //칸막이 필요하다
            current_min = 0; //최솟값 초기화
        }

        current_min = max(now_min,current_min);
    }

    cout<<ans;
    return 0;
}
