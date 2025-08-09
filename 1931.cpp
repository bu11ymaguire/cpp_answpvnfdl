#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare_pare(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> hello;
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        int one,two;
        cin>>one>>two;
        hello.push_back({one,two});
    }

    sort(hello.begin(),hello.end(),compare_pare);

    int count = 0;
    int next_time = 0;
    for(auto haha:hello)
    {
        if(haha.first >=next_time){ //한 회의가 끝나는 '동시에' 다음 회의가 시작될 수 있다. '<='
            count++;
            next_time = haha.second;
        }
    }

    cout<<count;
    return 0;
}
