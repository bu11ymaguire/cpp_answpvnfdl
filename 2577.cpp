#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number[10]={0};
    int a,b,c,times;
    cin>>a>>b>>c;
    times = a * b * c;
    int M=1000000000;
    for(M;M>=1;M=M/10)
    {
        if(times>M){
            break;
        }
    }
    for(int i=M;i>=1;i=i/10){
        number[times/i]++;
        times = times%i;
    }
    for(int i=0;i<10;i++)
    {
        cout<<number[i]<<'\n';
    }
    return 0;
}
