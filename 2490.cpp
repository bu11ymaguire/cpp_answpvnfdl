#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> yut(2);
    int tmp;
    for(int i=0;i<3;i++)
    {
        yut[0]=0;
        yut[1]=0;
        for(int j=0;j<4;j++)
        {
            cin>>tmp;
            yut[tmp]++;
        }
        if(yut[0]==4){cout<<"D\n";}
        else if(yut[0]==3){cout<<"C\n";}
        else if(yut[0]==2){cout<<"B\n";}
        else if(yut[0]==1){cout<<"A\n";}
        else if(yut[0]==0){cout<<"E\n";}
    }
    return 0;
}
