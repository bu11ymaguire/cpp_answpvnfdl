#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long line;
    int N,tmp;
    cin>>N>>line;
    vector<long long> group;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        group.push_back(tmp);
    }

    sort(group.begin(),group.end(),greater<long long>());

    long long high = group[0];
    long long low = 1;
    long long meter = 0;
    while(low<=high){
        long long mid = low + (high-low)/2;
        long long current_line = 0;
        for(int i=0;i<N;i++){
            if(mid>group[i]){
                break;
            }
            current_line += group[i]/mid;
        }
        if(current_line>=line){
            meter = mid;
            low = mid +1;
        }
        else if(current_line<line){
            high = mid -1;
        }
    }
    cout<<meter;
    return 0;
}
