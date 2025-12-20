//시간초과
#include<bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int i)
{
    vector<char> see_ya_chump;
    for(int l = 0; l < s2.size(); l++)
    {
        if(s1[l+i]==s2[l])
        {
           see_ya_chump.push_back(s2[l]);
        }
    }
    if(see_ya_chump.size()>=2) return see_ya_chump.size();
    return 0;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int N, m;
    cin >> N >> m;
    string s1, s2; cin >> s1 >> s2;

    int result = 0;
    for(int i = 0; i < N-m+1; i++)
    {
        result += lcs(s1,s2,i);
    }

    cout << result;
    

    return 0;
}
