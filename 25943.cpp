#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int N;cin>>N;
    vector<int> hello(N);

    for(int i = 0; i < N ; i ++)
    {
        cin>>hello[i];
    }

    int left = hello[0];
    int right = hello[1];
    
    for(int i = 2; i < N ; i++)
    {
        if(left==right)
        {
            left+=hello[i];
        }
        else if(left>right){
            right+=hello[i];
        }else if(left<right){
            left+=hello[i];
        }
    }

    if(left==right)
    {
        cout<<0;
    }
    else
    {
        int diff = max(left-right,right-left);
        vector<int> hi = {100,50,20,10,5,2,1};

        int sum = 0;
        for(const auto haha:hi)
        {
            sum += diff/haha; //무개추의 개수에는 제한이 없다
            diff = diff%haha;
            if(diff==0){break;}
        }

        cout<<sum;
    }

    return 0;
}
