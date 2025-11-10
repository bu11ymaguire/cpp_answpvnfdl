#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int from, to;
    cin >> from >> to;
    if(from==to){
        cout << 0;
        return 0;
    }

    vector<int> visited(1000001,0);

    queue<int> q;
    q.push(from);

    while(visited[to]==0)
    {
        int now = q.front();
        q.pop();

        int Now = now + 1;
        if(Now<=1000000){
            if(visited[Now]==0){
            q.push(Now);
            visited[Now] = visited[now] + 1;
        }
        }

        int nOw = 2 * now;

        if(nOw<=1000000){
            if(visited[nOw]==0)
           {
            q.push(nOw);
            visited[nOw] = visited[now] + 1;
           }
        }
    }
    cout << visited[to];
    return 0;
}
