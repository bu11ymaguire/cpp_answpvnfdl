#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    queue<int> hello;
    for(int i=1;i<=n;i++)
    {
        hello.push(i);
    }
    while(hello.size()>1)
    {
        hello.pop();
        int tmp = hello.front();
        hello.pop();
        hello.push(tmp); 
    }
    cout << hello.front();
    return 0;
}
