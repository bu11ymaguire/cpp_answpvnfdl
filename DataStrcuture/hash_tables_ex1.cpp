#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int,int> hello;
    bool duplicated = false;
    int N,tmp;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>tmp;
        if(hello[tmp]!=0)
        {
            duplicated = true;
            break;
        }
        hello[tmp]++;
    }
    if(duplicated){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}
