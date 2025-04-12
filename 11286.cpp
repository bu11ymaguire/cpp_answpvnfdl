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

    priority_queue<int,vector<int>,greater<int>> plus; 
    //처음에는 deque을 이용해서 데이터를 쌓고 입력값이 0이 나올때 sort를 했는데, 이러니까 시간초과가 뜸.
    priority_queue<int,vector<int>,greater<int>> minus;

    int in;
    for(int i=1;i<=command;i++)
    {
        cin >>in;

        if(in==0)
        {
            if(plus.empty()&&minus.empty())
            {
                cout<<in<<'\n';
            }
            else if(plus.empty()){
                cout<<-minus.top()<<'\n';
                minus.pop();
            }
            else if(minus.empty()){
                cout<<plus.top()<<'\n';
                plus.pop();
            }
            else
            {
                if(plus.top()>=minus.top()){
                    cout<<-minus.top()<<'\n';
                    minus.pop();
                }
                else{
                    cout<<plus.top()<<'\n';
                    plus.pop();
                }
            }
        }

        if(in<0){
            in = (-1)*in;
            minus.push(in);
        }
        else if(in>0)
        {
            plus.push(in);
        }
    }
    return 0;
}
