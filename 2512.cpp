#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,total,sum;
    cin>>N;
    vector<int> hello(N);

    int L=0,R=0;
    sum = 0;
    for(int i=0;i<N;i++)
    {
        cin>>hello[i];
        sum+=hello[i];
        if(R<=hello[i])
        {
            R=hello[i];
        }
    }
    cin>>total;
    if(sum<=total){cout<<R;return 0;}

    int mid;
    int answer;
    while(L<=R){
        sum = 0;
        mid = (R-L)/2 + L;
        for(int x:hello){
            sum+= min(mid,x);
        }
        if(sum<=total){
            answer=mid;
            L = mid+1;
        }else{
            R = mid-1;
        }
    }
    cout<<answer;
    return 0;
}
