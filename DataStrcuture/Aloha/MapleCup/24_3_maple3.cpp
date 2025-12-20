#include<bits/stdc++.h>
using namespace std;
//https://project-ps.com/problem/135

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long m; 
    cin >> N >> m;
    m *=100;
  /*
  ratio = (one * two)/100 보다는
  m *= 100이 더 낫다.
  */
    
    long long result = LLONG_MAX;

    while(N--)
    {
        long long one,two,price;
        cin >> one >> two >> price;
        if(one==0) continue;
        if(price == 0 )
        {
           result = 0;
           continue;
        }
        long long ratio = one * two;
        long long now_price;
        if(m%ratio==0){
            now_price = (m/ratio) * price;
        }else{
            now_price = (m/ratio+1) * price;
        }
        if(result>now_price)
        {
            result = now_price;
        }   
    }
    if(result==LLONG_MAX)
    {
        cout << -1;
    }else{
        cout << result;
    }
    return 0;
}
