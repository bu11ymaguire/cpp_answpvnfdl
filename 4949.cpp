4949
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string input;
    getline(cin,input);
    while(input!=".")
    {
        stack<char> balance;
        bool check =true;
        for(int i=0;i<input.length();i++)
        {
            if(input[i]=='(')
            {
                balance.push('(');
            }
            else if(input[i]==')')
            {
                if(!balance.empty()&&balance.top()=='(') //조건문에서 중요한 조건을 앞에 두기
                {
                    balance.pop();
                }
                else
                {
                    check = false;
                    break;
                }
            }
            else if(input[i]=='[')
            {
                balance.push('[');
            }
            else if(input[i]==']')
            {
                if(!balance.empty()&&balance.top()=='[') //조건문에서 중요한 조건을 앞에 두기
                {
                    balance.pop();
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }   
        if(balance.empty()&&check==true)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        getline(cin,input);   
    }
    return 0;
}
