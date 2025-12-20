#include<bits/stdc++.h>
using namespace std;
//https://project-ps.com/problem/127
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;

    while(N--)
    {
        string input; cin >>input;
        if(input[input.size()-1]!='!')
        {
            cout << input <<'\n';
        }else{
            if(input=="<!"){
                cout <<">\n";
            }else if(input==">!")
            {
                cout << "<\n";
            }else{
                cout <<"<>\n";
            }
        }
    }
    return 0;
}
