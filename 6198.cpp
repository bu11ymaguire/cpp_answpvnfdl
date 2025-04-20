#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n,tmp;
    cin>>n;
    stack<long long> hello;
    long long total =0;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        while(!hello.empty()&&hello.top()<=tmp)
        {
            hello.pop();
        }
        total+=hello.size();
        hello.push(tmp);
    }
    cout<<total;
}
