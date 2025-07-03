#include<iostream>
#include<vector>
#include<algorithm>
//해당 로프를 이용해서 들 수 있는 최대 중량찾기
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int> hello;
    int n; cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        hello.push_back(tmp);
    }
    sort(hello.begin(),hello.end(),greater<int>());
    int max = 0;
    for(int i=0;i<n;i++){
        int result = hello[i]*(i+1);
        if(max<result){
            max = result;
        }
    }
    cout<<max;
    return 0;
}
