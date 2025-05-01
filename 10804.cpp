#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int hello[20];
    for(int i=0;i<20;i++){
        hello[i]=i+1;
    }
    int a,b;
    for(int i=0;i<10;i++){
        cin>>a>>b;
        a--;
        b--;
        for(int j=0;j<=(b-a)/2;j++){
            swap(hello[a+j],hello[b-j]);
        }
    }
    for(int i=0;i<20;i++){
        cout<<hello[i]<<" ";
    }
    return 0;
}
