#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, value;
    cin>>n>>value;
    vector<int> coin(n);

    for(int i=0;i<n;i++){
        cin>>coin[i];
    }

    int coins = 0;
    int current;

    for(int i=n-1;i>=0;i--)
    {
        if(value==0){
            break;
        }
        current = value /coin[i];
        coins+=current;
        value -= current*coin[i];
    }
    cout<<coins; //최종출력은 안전하게 반복문 밖에서
    return 0;
}

