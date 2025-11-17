#include<bits/stdc++.h>
using namespace std;

bool visted[9];
vector<int> arr;

int n,m;

void DFS(int hello)
{
    if(hello==m)
    {
        for(const auto& num: arr)
        {
            cout << num <<' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i<=n; i++)
    {
        if(visted[i])continue;
        visted[i] = true;
        arr.push_back(i);
        DFS(hello+1);
        visted[i] = false;
        arr.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    DFS(0);
    return 0;
}
