#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio((false));
    cin.tie(0);cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int> hello(21,0);
    string order;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>order;
        if(order=="add"){
            cin>>x;
            hello[x]=1;
        }

        else if(order=="remove"){
            cin>>x;
            hello[x]=0;
        }

        else if(order=="check"){
            cin>>x;
            cout<<hello[x]<<'\n';
        }

        else if(order=="toggle"){
            cin>>x;
            if(hello[x]==0){hello[x]=1;}
            else{hello[x]=0;}
        }

        else if(order=="all")
        {
            for(int i=1;i<=20;i++){hello[i]=1;}
        }

        else if(order=="empty"){for(int i=1;i<=20;i++){hello[i]=0;}}
    }

    return 0;
}
