#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> alpah(26);
    int N; cin >> N;

    while(N--)
    {
        char from, to;
        string is;
        cin >> from >> is >> to;
        int FROM = (int)from - (int)'a';
        int TO = (int)to - (int)'a';
        alpah[FROM].push_back(TO);
    }

    int q; cin >> q;
    while(q--)
    {
        vector<bool> visit(26,false);
        char from, to;
        string is;
        cin >> from >> is >> to;
        int FROM = (int)from - (int)'a';
        int TO = (int)to - (int)'a';

        stack<int> s;
        s.push(FROM);

        while(!s.empty())
        {
            int now = s.top();
            s.pop();
            if(visit[now]) continue;
            visit[now] = true;
            for(int i =0; i < alpah[now].size();i++)
            {
                s.push(alpah[now][i]);
            }
        }

        if(visit[TO]) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}
