#include<iostream>
#include<stack>
#include<string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string number;
    cin>>number;
    while(number!="0"){
        stack<char> pellindrome;
        bool is_pellindrome = false;
        for(int i=0;i<number.length();i++){
        if(i<(number.length())/2){
            pellindrome.push(number[i]);
        }
        else
        {
            if((i==number.length()/2)&&(number.length()%2!=0)){continue;}
            if((!pellindrome.empty())&&pellindrome.top()==number[i]){pellindrome.pop();}
        }}
        if(pellindrome.empty()){is_pellindrome=true;}
        if(is_pellindrome){cout<<"yes\n";}
        else{cout<<"no\n";}
        cin>>number;
    }
    return 0;    
}
