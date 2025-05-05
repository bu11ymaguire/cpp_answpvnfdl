#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> hello;
    int tmp,N;
    cin>>tmp;
    for(int i=1000000000;i>=1;i=i/10)
    {
        if(tmp>=i){
            N=i;
            break;
        }
    }

    for(N;N>=1;N=N/10)
    {
        hello.push_back(tmp/N);
        tmp = tmp%N;
    }
    sort(hello.begin(),hello.end());

    for(int i=hello.size()-1;i>=0;i--){
        cout<<hello[i];
    }

    return 0;
}
