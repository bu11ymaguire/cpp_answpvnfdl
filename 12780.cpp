#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;

    string a;
    string b;
    cin>>a>>b;

    for(int i=0;i<=a.length()-b.length();)
    {
        bool check = true;
        for(int j=i;j<i+b.length();j++)
        {
            if(a[j]!=b[j-i]){
                check = false;
                break;
            }
        }
        if(check){
            n++;
            i+=b.length();
        }else{
            i++;
        }
    }
    cout<<n;
    return 0;
}
