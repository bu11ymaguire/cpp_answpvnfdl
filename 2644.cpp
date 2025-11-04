#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int member; cin >> member;

    vector<vector<int>> family(member+1);

    int from, to; cin >> from >> to;
    vector<int> chone(member+1,-1);
    vector<bool> visited(member+1,false);

    chone[from] = 0;
    visited[from] = true;

    int N; cin >> N;
    while(N--)
    {
        int f,t; cin >> f >> t;
        family[f].push_back(t);
        family[t].push_back(f);
    }

    stack<int> s;
    s.push(from);
    visited[from] = true;
    while(!s.empty())
    {
        int now = s.top();
        s.pop();
        for(const auto& hi: family[now])
        {
            if(!visited[hi])
            {
                visited[hi] = true;
                chone[hi] = chone[now] + 1;
                s.push(hi);
            }
        }
    }
    cout << chone[to];
    return 0;
}
