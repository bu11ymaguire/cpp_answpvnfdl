#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tre;
    cin >> tre;
    for(int i =1; i<=tre;i++)
    {
        int n,m;
        cin>>n>>m;
        vector<int> group(n);
        queue<pair<int,int>> duo; //숫자와 순서까지 고려해야되는 경우 pair을 이용하면 편하다.
        for(int j=0;j<n;j++)
        {
            cin>>group[j];
            duo.push({j,group[j]});
        }
        sort(group.begin(),group.end(),greater<int>());

        int idx=0;
        int count = 0;
        while(!duo.empty())
        {
            pair<int,int> yeah = duo.front();
            duo.pop();
            if(yeah.second==group[idx])
            {
                idx++;
                count++;
                if(yeah.first == m)
                {
                    break;
                }
            }
            else
            {
                duo.push(yeah);
            }
        }
        cout << count <<'\n';
    }
    return 0;
}
