#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int,int> um;
    int N; cin >> N;
    while(N--)
    {
        int tmp; cin >> tmp;
        um[tmp]++;
    }
    int query; cin >> query; 
    cout << um[query];
    return 0;
}
