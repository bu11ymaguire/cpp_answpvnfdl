#include<iostream>
#include<cmath>
using namespace std;

long long find_prime(long long n)
{
    bool is_prime;
    for(long long i=n;;i++)
    {
        is_prime = true;
        for(long long j=2;j<=sqrt(i);j++)
        {
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){return i;}
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int in;
    cin>>in;

    long long tmp;
    for(int i=0;i<in;i++){
        cin>>tmp;
        if(tmp==0||tmp==1){
            cout<<2<<'\n';
        }
        else{
            cout<<find_prime(tmp)<<'\n';
        }
    }

    return 0;
}
