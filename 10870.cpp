#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum[21];
    for(int i=0;i<=20;i++){
        if(i==0||i==1){
            sum[i]=i;
        }
        else{
            sum[i]=sum[i-1]+sum[i-2];
        }
    }
    int in;
    cin>>in;
    cout<<sum[in];
    return 0;
}
