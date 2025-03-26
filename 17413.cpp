#include<iostream>
#include<string>
#include<stack>
using namespace std;

int  main()
{
    string in;
    getline(cin, in);
    stack<char> check;
    stack<char> reverse;
    for(int i=0;i<(int)(in.length());i++)
    {
        if((char)in[i]=='<') //'<'부터는 제대로 출력 
        {
            while(!reverse.empty())
            {
                cout << reverse.top();
                reverse.pop();
            }
            check.push('<');
            cout << in[i];
        }
        else if(in[i]=='>')
        {
            check.pop();
            cout <<in[i];
        }
        else if(!check.empty())
        {
            cout <<in[i];
        }
        else if(in[i]==' ')
        {
            while(!reverse.empty())
            {
                cout<<reverse.top();
                reverse.pop();
            }
            cout<<in[i];
        }
        else
        {
            reverse.push(in[i]);
        }
    }


    if(!reverse.empty()) //출력하기전에 스택다 털기기
    {
        while(!reverse.empty())
        {
            cout<<reverse.top();
            reverse.pop();
        }
    }
    return 0;
}
