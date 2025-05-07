#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string A,B;
    for(int i=0;i<n;i++)
    {
        cin>>A>>B;
        if(A.size()!=B.size()){cout<<"Impossible\n";continue;}
        vector<char> haha_a;
        vector<char> haha_b;
        for(int i=0;i<A.size();i++)
        {
            haha_a.push_back(A[i]);
        }
        for(int i=0;i<B.size();i++)
        {
            haha_b.push_back(B[i]);
        }
        sort(haha_a.begin(),haha_a.end());
        sort(haha_b.begin(),haha_b.end());
        for(int i=0;i<A.size();i++)
        {
            if(haha_a[i]!=haha_b[i]){
                cout<<"Impossible\n";
                break;
            }
            if(i==A.size()-1){cout<<"Possible\n";}
        }
    }

    return 0;
}
