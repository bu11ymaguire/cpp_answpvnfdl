#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> number(n);
    for(int i=0;i<n;i++)
    {
        cin>>number[i];
    }
    int possible = 0;
    int small = n+1;
    int sum = 0;

    int start = 0;

    for(int last=0;last<n;last++)
    {
        sum+=number[last];
        while(sum>=m&&start<=last)    ///이 수열에서 연속된 수들의 부분합 중에 그 합이 S '이상'이 되는 것
        {
            possible++;
            if(small>last-start+1)
            {
                small = last - start + 1;
            }
            sum-=number[start];
            start++;
        }
    }

    if(possible>0)
    {
        cout<<small;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
