#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s1;string s2;
    cin>>s1>>s2;
    vector<vector<int>> check(s1.size()+1,vector<int>(s2.size()+1,0));
    vector<vector<pair<int,int>>> root(s1.size()+1,vector<pair<int,int>>(s2.size()+1,{-1,-1}));
    vector<vector<char>> character(s1.size()+1,vector<char>(s2.size()+1,0));  

    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                check[i][j] = check[i-1][j-1]+1;
                character[i][j] = s1[i-1];
                root[i][j]= {i-1,j-1};
            }
            else{
                if(check[i][j-1]>=check[i-1][j])
                {
                    check[i][j] = check[i][j-1];
                    character[i][j]= character[i][j-1];
                    root[i][j]=root[i][j-1];
                }else if(check[i-1][j]>check[i][j-1])
                {
                    check[i][j] = check[i-1][j];
                    character[i][j] = character[i-1][j];
                    root[i][j]=root[i-1][j];
                }
            }
        }
    }
    cout<<check[s1.size()][s2.size()]<<'\n';
    int current_x = s1.size();
    int current_y = s2.size();

    char current_character = character[current_x][current_y];
    stack<char> output;

    while(current_character!=0)
    {
        output.push(current_character);
        int old_1 = current_x; int old_2 = current_y;
        current_x = root[old_1][old_2].first;
        current_y = root[old_1][old_2].second;
        current_character = character[current_x][current_y];
    }
    while(!output.empty()){
        cout<<output.top();
        output.pop();
    }
    return 0;
}
