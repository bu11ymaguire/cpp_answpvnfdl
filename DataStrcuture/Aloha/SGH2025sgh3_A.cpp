//올림픽 정신
#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin>>N;
    vector<int> hello(N);
    for(int i =0; i<N;i++)
    {
        cin>>hello[i];
    }
    cout<<hello[N-1]*2-hello[N-2];
    return 0;
}
