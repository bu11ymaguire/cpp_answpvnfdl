#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M,n;
    cin>>M>>n;

    vector<int> boy(6,0);
    vector<int> girl(6,0);

    int s,g;
    for(int i=0;i<M;i++)
    {
        cin>>s>>g;
        if(s==0){
            girl[g-1]++;
        }else{
            boy[g-1]++;
        }
    }

    int room = 0;
    for(int i=0;i<6;i++)
    {
        if(girl[i]%n==0){
            room+=girl[i]/n;
        }
        else{
            room+=girl[i]/n+1;
        }
    }

    for(int i=0;i<6;i++)
    {
        if(boy[i]%n==0){
            room+=boy[i]/n;
        }
        else{
            room+=boy[i]/n+1;
        }
    }

    cout<<room;
    
    return 0;
}
