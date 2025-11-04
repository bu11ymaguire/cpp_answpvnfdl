#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices,edges,start;
    cin>>vertices>>edges>>start;
    vector<vector<int>> hello(vertices+1);

    while(edges--)
    {
        int from, to;
        cin >> from >> to;
        hello[from].push_back(to);
        hello[to].push_back(from);
    }

    for(int i = 1; i <=vertices;i++)
    {
        if(hello[i].size()!=0)
        {
            sort(hello[i].begin(),hello[i].end(),greater<int>());
        }
    }

    vector<int> order(vertices+1,0);
    int qUEUE  = 1;

    stack<int> s;
    s.push(start);
    while(!s.empty())
    {
        int now = s.top();
        s.pop();

        if(order[now]!=0)continue; //방문을 어디서 카운트 하는가?

        order[now] = qUEUE;
        qUEUE++;

        for(const auto& hi : hello[now]){
            if(order[hi]==0)s.push(hi);
        }
    }

    for(int i =1; i <=vertices;i++)
    {
        cout << order[i] <<'\n';
    }

    return 0;
}
