#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int in,tmp;
    cin>>in;
    vector<int> hello;
    for(int i=0;i<in;i++){
        cin>>tmp;
        hello.push_back(tmp);
    }

    for(int i=0;i<in;i++){
        for(int j=i+1;j<in;j++){
            if(hello[i]>hello[j]){
                swap(hello[i],hello[j]);
            }
        }
    }

    for(int i=0;i<in;i++){
        cout<<hello[i]<<'\n';
    }
    return 0;
}
