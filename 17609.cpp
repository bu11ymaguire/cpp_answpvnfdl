#include<iostream>
using namespace std;

pair<int,int> check_palindrome(string input)
{
    int L = 0;
    int R = input.size()-1;
    while(L<R)
    {
        if(input[L]==input[R])
        {
            L++;
            R--;
        }
        else
        {
            return {L,R};
        }
    }
    return {-1,-1};
}

bool pseudo_pallindrome(string input, int L, int R)
{
    while(L<R)
    {
        if(input[L]==input[R])
        {
            L++;
            R--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--)
    {
        string input;
        cin>>input;
        auto result = check_palindrome(input);
        if(result.first==-1&&result.second==-1)cout<<0<<'\n';
        else
        {
            bool A = pseudo_pallindrome(input,result.first+1,result.second);
            bool B = pseudo_pallindrome(input,result.first,result.second-1);
            if(A||B)
            {
                cout<<1<<'\n';
            }
            else{
                cout<<2<<'\n';
            }
        }
    }
    return 0;
}
