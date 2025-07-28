#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s1;string s2;
    cin>>s1>>s2;
    vector<vector<int>> check(s1.size()+1,vector<int>(s2.size()+1,0));

    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1]){
                check[i][j] = check[i-1][j-1]+1;
            }
            else{
                check[i][j] = max(check[i][j-1],check[i-1][j]);
            }
        }
    }
    cout<<check[s1.size()][s2.size()];
    return 0;
}
