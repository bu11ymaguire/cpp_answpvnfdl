#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<int> order;
    int n;
    cin>>n;
    int sum =0;
    for(int i=1;i<=n;i++)
    {
        int number;
        cin>>number;
        if(number!=0)
        {
            order.push(number);
            sum+= number;
        }
        else
        {
            sum -= order.top();
            order.pop();
        }
    }
    cout<<sum;
    return 0;
}
