#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int limit,m;
    cin>>limit>>m;
    vector<pair<int,int>> hello(m+1,{0,0});

    for(int i=1;i<=m;i++)
    {
        cin>>hello[i].first>>hello[i].second;
    }

    vector<int> result(limit+100,(INT_MAX-1)/2); //조합을 딱 limit에 맞췄을때보다 limit를 약간 넘기는 경우가 더 저렴할수도 있다고 하네요
    result[0]=0;
   
    for(int i=1;i<=m;i++)
    {
        int current_exp = hello[i].second; //기대 관광객
        int current_value = hello[i].first;  //기대 값
        for(int j=current_exp;j<result.size();j++)
        {
            result[j] = min(result[j],result[j-current_exp]+current_value);
        }
    }

    int minimum = INT_MAX;
    for(int i=limit;i<=limit+99;i++)
    {
        if(minimum>result[i])
        {
            minimum = result[i];
        }
    }
    cout<<minimum;
    return 0;
}
