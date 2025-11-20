#include<bits/stdc++.h>
using namespace std;

vector<int> input;
int target;
int answer = 0;

void DFS(int idx, int sum, int cnt)
{
    if(idx == input.size())
    {
        if(cnt > 0 && sum == target)
        {
            answer++;
        }
        return;
    }

    DFS(idx+1,sum,cnt);
    DFS(idx+1,sum+input[idx],cnt+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N >> target;
    input.resize(N);

    for(int i = 0; i < N ; i++)
    {
        cin >> input[i];
    }

    DFS(0,0,0);

    cout << answer;


    return 0;
}
