#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int mini = n;
    bool possible = false;
    for(int i=mini;i>=0;i--)
    {
        int x = i * 5;
        int a = n - x;
        double j = (double)a/3;
        if((j>=0)&&(j-(int)j==0))
        {
            possible = true;
            if(j+i<mini)
            {
                mini = j+i;
            }
        }   
    }
    if(possible)
    {
        cout << mini;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
