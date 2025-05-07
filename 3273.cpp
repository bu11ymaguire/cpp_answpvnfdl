#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,tmp,target;
    cin>>N;
    vector<int> hello(N);
    for(int i=0;i<N;i++){
        cin>>tmp;
        hello[i] = tmp;
    }
    sort(hello.begin(),hello.end());
    cin>>target;
    int combination = 0;
    int a = 0;
    int b = N-1;
    while(a<b)
    {
        if(hello[a]+hello[b]==target)
        {
            combination++;
            a++;
        }else if(hello[a]+hello[b]<target)
        {
            a++;
        }else{
            b--;
        }
    }
    cout<<combination;
    return 0;
}
