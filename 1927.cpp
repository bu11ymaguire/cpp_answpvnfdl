#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int command;
    cin>> command;

    priority_queue<int,vector<int>,greater<int>> hellothere; //우선순위 큐는 기본적으로 내림차순이기 때무에 오름차순으로 하려면 greater<int>를 정렬해야됨.
    int in;
    for(int i=1;i<=command;i++)
    {
        cin>>in;
        if(in==0)
        {
            if(hellothere.empty())
            {
                cout<<in<<'\n';
            }
            else{
                cout<<hellothere.top()<<'\n';
                hellothere.pop();
            }
        }
        else{
            hellothere.push(in);
        }
    }
    
    return 0;
}
