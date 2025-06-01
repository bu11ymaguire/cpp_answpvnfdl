#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, tmp;
    long long goal;
    vector<int> hello_world;
    cin>>N>>goal;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        hello_world.push_back(tmp);
    }
    sort(hello_world.begin(),hello_world.end(),greater<int>());
    int low = 0;
    int high = hello_world[0];
    int answer = 0;

    while(low<=high){
        int mid = low + (high-low)/2;
        long long current__sum = 0;
        for(int i=0;i<N;i++)
        {
            if(hello_world[i]<=mid)
            {
                break;
            }
            current__sum += (hello_world[i]-mid);
        }
        if(current__sum>=goal){
            answer = mid;
            low = mid+1;
        } else if(current__sum<goal){
            high = mid-1;
        }
    }
    cout << answer;
    return 0;
}
