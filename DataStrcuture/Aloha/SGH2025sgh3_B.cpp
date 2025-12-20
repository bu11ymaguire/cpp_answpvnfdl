#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,m; cin>>N>>m;
    vector<pair<int,int>> hello(N+1,{0,0});
    vector<int> result(m+1,0);

    for(int i =1; i<=N;i++)
    {
        int a,b; cin>>a>>b;
        hello[i]={a,b};
    }

    for(int i =1; i<=m;i++)
    {
        int win =0;
        int game,a,b; cin>>game>>a>>b;
        for(int j=1;j<=N;j++)
        {
            auto now = hello[j];
            if(now.first+now.second>game)continue;
            if(now.first<a||now.second<b)continue;
            int one = now.first - a;
            int two = now.second - b;
            if(one+two<=game)
            {
                win++;
            }
        }
        result[i] = win;
    }

    for(int i = 1; i <=m; i++){
        cout<<result[i]<<'\n';
    }

    return 0;
}
