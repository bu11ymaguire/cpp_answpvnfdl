#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,goal; cin>>N>>goal;

    vector<int> input(N);
    for(int i = 0 ; i < N; i++)
    {
        cin>>input[i];
    }

    int sum = 0;
    int length = 100002;
    int L = 0;
    for(int R = 0; R < N; R++)
    {
        sum+= input[R];
        while(sum>=goal)
        {
            length = min(length,R-L+1);
            sum-=input[L];
            L++;
        }
    }

    if(length==100002){
        cout<<0;
        return 0;
    }

    cout<<length;
    return 0;
}
