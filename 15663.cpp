#include<bits/stdc++.h>
using namespace std;

map<string,bool> visited;
vector<int> arr;
vector<int> input;

int n,m;

void DFS(int hello)
{
    if(hello==m)
    {
        string confrim;
        for(int i = 0; i < hello; i++)
        {
            confrim += 
        }
        cout << '\n';
        return;
    }

    for(int i =0; i < n; i++)
    {
        if(visited[i]==hello)continue;
        arr.push_back(input[i]);
        visited[i]++;
        DFS(hello+1);
        arr.pop_back();
        visited[i]--;
    }
}

int main()
{
    cin >> n >> m;
    input.resize(n);
    sort(input.begin(),input.end());
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    DFS(0);
    return 0;
}
