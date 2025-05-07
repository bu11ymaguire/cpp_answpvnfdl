#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int alpha[26]={0};
    string sentence;
    cin>>sentence;
    for(int i=0;i<sentence.size();i++){
        alpha[(int)sentence[i]-97]++;
    }
    for(int i=0;i<26;i++){
        cout<<alpha[i]<<' ';
    }
    return 0;
}
