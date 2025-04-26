#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tri,in,put;
    cin>>tri;
    deque<int> problem;
    for(int i=1;i<=tri;i++){
        cin>>in;
        switch (in)
        {
        case 1:
            cin>>put;
            problem.push_front(put);
            break;
        case 2:
            cin>>put;
            problem.push_back(put);
            break;
        case 3:
            if(problem.empty()){cout<<-1<<'\n';}
            else{
                cout<<problem.front()<<'\n';
                problem.pop_front();
            }
            break;
        case 4:
            if(problem.empty()){cout<<-1<<'\n';}
            else{
                cout<<problem.back()<<'\n';
                problem.pop_back();
            }
            break;    
        case 5:
            cout<<problem.size()<<'\n';
            break;    
        case 6:
            if(problem.empty()){cout<<1<<'\n';}
            else{cout<<0<<'\n';}
            break;
        case 7:
            if(problem.empty()){cout<<-1<<'\n';}
            else{cout<<problem.front()<<'\n';}
            break;
        case 8:
            if(problem.empty()){cout<<-1<<'\n';}
            else{cout<<problem.back()<<'\n';}
            break;        
        default:
            break;
        }
    }
    return 0;
}
