//메모리초과
#include<bits/stdc++.h>
using namespace std;


int lcs(string &s1, string &s2, int i)
{
    int length = 0;
    vector<vector<int>> bully(s2.size(),vector<int>(s2.size(),0));
    for(int l = 0; l < s2.size(); l++)
    {
        if(s1[l+i]==s2[l])
        {
            if(l==0){
                bully[l][l] = 1;
            }
            else
            {
                bully[l][l] = bully[l-1][l-1] + 1;
            }
            length = bully[l][l];
        }
    }
    if(length>=2) return length;
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
