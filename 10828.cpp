#include<iostream>
#include<string>
#include<stack>
#include <limits>
using namespace std;

int  main()
{
    int n;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    stack<int> stk;
    for(int i=1;i<=n;i++)
    {
        string order;
        cin>>order;

       if(order=="push")
       {
        int num;
        cin>>num;
        stk.push(num);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }

       if (order=="pop")
       {
        if(stk.empty())
        {
            cout<<-1<<endl;
        }
        else{
            cout<<stk.top()<<endl;
            stk.pop();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        
       }

       if(order=="size")
       {
        cout<<stk.size()<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }

       if(order=="empty")
       {
        if(stk.empty()){
            printf("%d\n",1);
        }
        else{
            printf("%d\n",0);
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
       if(order=="top")
       {
        if(stk.empty())
        {
            cout<<-1<<endl;
        }else
        {
            cout<<stk.top()<<endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
    }
    return 0;
}
