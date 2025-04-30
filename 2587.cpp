#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int total,tmp;
    total = 0;
    vector<int> hello(5,0);
    for(int i=0;i<5;i++)
    {
        cin>>tmp;
        hello[i]=tmp;
        total+=tmp;
    }
    sort(hello.begin(),hello.end());
    int avg = total/5;
    cout<<avg<<'\n';
    cout<<hello[2];

    return 0;
}


