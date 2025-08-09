#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int number;
    long long limit,discount;
    cin>>number>>limit>>discount;

    vector<long long> hello(number);
    for(int i=0;i<number;i++)
    {
        cin>>hello[i];
    }

    sort(hello.begin(),hello.end()); //오름차순
    
    vector<long long> prefix(number, 0);

    prefix[0] = hello[0];

    for(int i=1;i<number;i++)
    {
        prefix[i] = prefix[i-1] + hello[i];
    }

    int ans=0;
    //전체 구매부터
    //가장 비싼 물건에 할인 쿠폰 적용!
    //만약 할인적용받은 가격이 limit 조건에 부합하면 조건문 break!
 
    for(int i=number-1;i>=0;i--) //0-base라 number-1
    {
        long long current_discount = min((long long)i+1,discount); //할인 적용이 구매할 물품보다 많은 경우 방지. 0-base라 i+1
        long long discounted;

        if(i<current_discount)
        {
            discounted = prefix[i]; //ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
        } else{
            discounted = prefix[i] - prefix[i-current_discount];
        }

        long long result = prefix[i] - (discounted/2);
        if(result<=limit){
            ans = i+1;
            break;
        }
    }

    cout<<ans;
    return 0;
}
