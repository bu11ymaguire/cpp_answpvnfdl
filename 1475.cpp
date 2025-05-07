#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> i_need_max;
    int number[10]={0};
    int six_nine = 0;
    int input;
    cin>>input;
    int M = 1000000;
    for(M;M>=1;M=M/10)
    {
        if(input>=M){break;}
    }
    for(int i=M;i>=1;i=i/10)
    {
        if(input/i==6||input/i==9)
        {
            six_nine++;
        }
        else{
            number[input/i]++;
        }
        input = input%i;
    }
    if(six_nine%2==1)
    {
        six_nine = six_nine/2 + 1;
    }else{six_nine = six_nine/2;}
    i_need_max.push(six_nine);

    for(int i=0;i<10;i++){
        i_need_max.push(number[i]);
    }
    cout<<i_need_max.top();
    return 0;
}
