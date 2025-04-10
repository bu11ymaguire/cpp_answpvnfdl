#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int go,back,goal;
    cin >>go >>back >>goal;


    int day = ceil((double)(goal-go)/(go-back))+1;
    cout << day;
}
