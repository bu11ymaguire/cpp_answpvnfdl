#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;
    int m=1;
    int small;
    if(A>=B){
        small=B;
    }
    else{
        small=A;
    }
    for(int i=1;i<=small;i++)
    {
        if(A%i==0&&B%i==0)
        {
            m=i;
        }
    }
    cout<<m<<endl;
    int total = A*B/m;
    cout<<total<<endl;
    return 0;
}
