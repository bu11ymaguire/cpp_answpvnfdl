#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp;
    cin>>tmp;
    vector<int> hello(tmp+1);
    hello[1]=0;
    for(int i=2;i<=tmp;i++){
        hello[i]=hello[i-1]+1;
        if(i%2==0){
            hello[i] = min(hello[i],hello[i/2]+1);
        }
        if(i%3==0){
            hello[i] = min(hello[i],hello[i/3]+1);
        }
    }
    cout<<hello[tmp];
    return 0;
}
