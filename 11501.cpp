#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//날 별로 주가를 예상하고 언제나 그게 맞아떨어진다. ->역순 그리티 탐색
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    for(int i =0 ; i < test ; i++)
    {
        int day;
        cin>>day;
        vector<int> price(day);
        for(int j = 0; j < day ; j++)
        {
            cin>>price[j];
        }

        int max_price = 0;
        long long sum = 0; //경우에 따라 sum이 int에서 오버플로우 발생 가능성 존재

        for(int j = day-1; j>=0; j--)
        {
            if(price[j]<=max_price)
            {
                sum += max_price - price[j];
            }else{
                max_price = price[j];
            }
        }cout<<sum<<'\n';
    }
    return 0;
}
