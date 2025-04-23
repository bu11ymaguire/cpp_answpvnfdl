#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int hello[10001]= {0};
    int in,m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>in;
        hello[in]++;
    }

    for(int i=1;i<=10000;i++){
        while(hello[i]>0){
            cout<<i<<'\n';
            hello[i]--;
        }
    }
    return 0;
}
