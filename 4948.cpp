#include<iostream>
#include<cmath>
using namespace std;

int find_prime(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){return 0;}
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int in;
    cin>>in;
    while(in!=0){
        int sum =0;
        for(int j=in+1;j<=2*in;j++){
            sum+=find_prime(j);
        }
        cout<<sum<<'\n';
        cin>>in;
    }


    return 0;
}
