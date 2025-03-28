#include<iostream>
#include<string>
#include<queue>
#include <limits>
using namespace std;

int  main()
{
    int n;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    queue<int> siuu;
    for(int i=1;i<=n;i++)
    {
        string order;
        cin>>order;

       if(order=="push")
       {
        int num;
        cin>>num;
        siuu.push(num);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }

       if (order=="pop")
       {
        if(siuu.empty())
        {
            printf("-1\n");
        }
        else
        {
            cout<<siuu.front()<<"\n";
            siuu.pop();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        
       }

       if(order=="size")
       {
        cout<<siuu.size()<<"\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }

       if(order=="empty")
       {
        if(siuu.empty())
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
       if(order=="front")
       {
        if(siuu.empty())
        {
            printf("-1\n");
        }
        else
        {
            cout<<siuu.front()<<"\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
       if(order=="back")
       {
        if(siuu.empty())
        {
            printf("-1\n");
        }
        else
        {
            cout<<siuu.back()<<"\n";
        }
       }
    }
    return 0;
}
