#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    unordered_map<string,int> hello;
    int n=0;
    int m,o;
    cin>>m>>o;
    string input;
    for(int i=0;i<m;i++){
        cin>>input;
        hello[input] = 1;
    }
    for(int i=0;i<o;i++){
        cin>>input;
        if(hello[input]==1){
            n++;
        }
    }
    cout<<n;
    return 0;
}
