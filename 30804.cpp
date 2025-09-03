#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin>>N; vector<int> fruits(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin>>fruits[i];
    }
    unordered_map<int,int> check_fruit;

    int l = 0;
    int max_length = 0;
    for(int r = 0; r < N; r++)
    {
        check_fruit[fruits[r]]++;

        while(check_fruit.size()>2)
        {
            check_fruit[fruits[l]]--;
            if(check_fruit[fruits[l]]==0)
            {
                check_fruit.erase(fruits[l]); //check_fruit.size()가 정확한 key의 개수를 샐 수 있도록 보정!
            }
            l++;
        }

        max_length = max(max_length,r-l+1);
    }
    cout<<max_length;
    return 0;
}
