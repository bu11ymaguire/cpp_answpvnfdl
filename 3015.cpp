#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    stack<pair<int,int>> hello_world;
    long long result = 0;
    for(int i=1;i<=n;i++)
    {
        int height;
        cin>>height;
        int count = 1;

        while(!hello_world.empty()&&hello_world.top().first<=height)
        {
            
            if(hello_world.top().first==height)
            {
                count+=hello_world.top().second;
            }

            result+=hello_world.top().second;
            hello_world.pop();
        }

        if(!hello_world.empty()) result++;

        hello_world.push({height,count});
    }
    cout<<result;
    return 0;
}
