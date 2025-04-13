#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int in;
    cin>>in;
    vector<int> hello(in);
    for(int i=0;i<in;i++)
    {
        cin>>hello[i];
    }
    sort(hello.begin(),hello.end());
    int sum = 0;
    for(int i=0;i<in;i++){
        sum+= hello[i]*(in-i);
    }

    cout<<sum;

    return 0;
}
