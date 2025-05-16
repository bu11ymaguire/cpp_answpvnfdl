#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int plus[10000001]={0};
    int minus[10000001]={0};
    int N,tmp,M;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        if(tmp>=0)
        {
            plus[tmp]=1;
        }
        else
        {
            tmp=-tmp;
            minus[tmp]=1;
        }
    }
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>tmp;
        if(tmp>=0)
        {
            cout<<plus[tmp]<<' ';
        }else{
            tmp = -tmp;
            cout<<minus[tmp]<<' ';
        }    
    }
    return 0;
}
