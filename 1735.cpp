#include<iostream>
using namespace std;
int get_cg(int a,int b) //전수조사는 안되니 유클리드 호제법 사용
{
    int x,y;
    if(a==b){return a;}
    else if(a>b)
    {
        x= a; y=b;
    }
    else
    {
        x = b; y = a;
    }
    while(y!=0){
        int tmp = y;
        y = x%y;
        x = tmp;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A_1,A_2;
    cin>>A_1>>A_2;
    int B_1,B_2;
    cin>>B_1>>B_2;
    int x = A_1*B_2 + B_1*A_2;
    int y = A_2 * B_2;
    int z = get_cg(x,y);
    x = x/z;
    y = y/z;
    cout<<x<<" "<<y;
    return 0;
}
