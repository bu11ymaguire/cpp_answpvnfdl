#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int stA[26] = {0};
    int stB[26] = {0};
    string A,B;
    cin>>A>>B;
    int tmp;
    for(int i=0;i<A.size();i++){
        tmp = (int)A[i]-(int)'a';
        stA[tmp]++;
    }
    for(int i=0;i<B.size();i++){
        tmp = (int)B[i]-(int)'a';
        stB[tmp]++;
    }
    int diff = 0;
    for(int i=0;i<26;i++){
        if(stA[i]>stB[i]){
            diff += stA[i]-stB[i];
        }else{
            diff+=stB[i]-stA[i];
        }
    }

    cout<<diff;

    return 0;
}
