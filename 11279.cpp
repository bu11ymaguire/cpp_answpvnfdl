#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int,vector<int>> hello;

    int tri;
    cin>>tri;
    int in;
    for(int i=0;i<tri;i++)
    {
        cin>>in;
        if(in==0){
            if(hello.empty())
            {
                cout<<in<<'\n';
            }
            else
            {
                cout<<hello.top()<<'\n';
                hello.pop();
            }
        }
        else{
            hello.push(in);
        }
    }
    return 0;
}
