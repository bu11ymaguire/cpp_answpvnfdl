#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string,int> um;

    int N; cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        string input;
        cin >> input;
        um[input] = i;
    }
    int count = 0;
    vector<bool> check(N,false);
    for(int i = 0 ; i < N; i++)
    {
        string input;
        cin >> input;
        int before = um[input]; //input의 예전 번호 순회.

        bool checking = false;
        for(int j = 0 ; j <before; j++) //터널에 들어왔던 순서대로 나갔는지 확인.
        {
            if(!check[j]) //터널에 들어왔던 순서대로 나가지 않았다면, 해당 자동차는 반드시 추월을 했음
            {
                checking = true; //추월 카운트.
                break;
            }
        }

        if(checking) count++;
        check[before] = true; //들어올떄 before 번째로 들어온 자동차는 어쨌든 나갔음.
    }

    cout << count;
    return 0;
}
