#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<int> hello;

    int order;
    cin>>order;
    int menu;
    int put;
    for(int i=0;i<order;i++)
    {
        cin>>menu;
        switch (menu)
        {
        case 1:
            cin>>put;
            hello.push(put);
            break;
        
        case 2:
            if(hello.empty()){cout<<-1<<'\n';}
            else{cout<<hello.top()<<'\n';hello.pop();}
            break;

        case 3:
            cout<<hello.size()<<'\n';
            break;
        case 4:
            if(hello.empty()){cout<<1<<'\n';}
            else{cout<<0<<'\n';}
            break;

        case 5:
            if(hello.empty()){cout<<-1<<'\n';}
            else{cout<<hello.top()<<'\n';}
            break;

        default:
            break;
        }
    }
    return 0;
}
