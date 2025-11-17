#include<bits/stdc++.h>
using namespace std;

set<vector<int>> printed; //set에다가 벡터도 넣을 수 있다!
vector<bool> visited;
vector<int> arr;
vector<int> input;

int n,m;

void DFS(int hello)
{
    if(hello==m)
    {
        if(printed.count(arr)) return;
        printed.insert(arr);  

        for(int i = 0; i < hello ; i++)
        {
            cout << arr[i] <<' ';
        }
        cout << '\n';
        return;
    }

    for(int i =0; i < n; i++)
    {
        if(visited[i])continue;
        visited[i] = true;
        arr.push_back(input[i]);
        DFS(hello+1);
        arr.pop_back();
        visited[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    input.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    sort(input.begin(),input.end());

    DFS(0);
    return 0;
}
