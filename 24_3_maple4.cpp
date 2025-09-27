#include<bits/stdc++.h>
using namespace std;
//https://project-ps.com/problem/140

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int game_pass_level = 0;
    int cash = 0;

    int target; cin >> target;
    int K,X; cin >> K >> X;
    int level, exp; cin >> level >> exp;
    vector<int> lvup_cash(101,0);

    lvup_cash.push_back(0);
    int tmp;
    int i = 1;

    while(cin>>tmp)
    {
        lvup_cash[i] = tmp;
        i++;
    }

    int levelup = exp/X;

    game_pass_level += levelup;
    if(game_pass_level>=target)
    {
        cout <<"yeah!";
        return 0;
    }

    int new_level = level + levelup;

    for(int j= 1; j<=levelup; j++)
    {
        cash+=lvup_cash[j];
    }

    int cashlevelup = cash/K;

    new_level +=cashlevelup;
    game_pass_level += cashlevelup;

    if(game_pass_level>=target) cout << "yeah!";
    else cout << "no...";
    return 0;
}
