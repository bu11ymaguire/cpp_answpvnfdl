#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    queue<int> series;
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            series.push(i);
        }
    }
    else
    {
        for(int i=m;i<=n;i++)
        {
            series.push(i);
        }
        for(int i=1;i<m;i++)
        {
            series.push(i);
        }
    }
    printf("<");
    for(int i=0;true;i++)
    {
        int a =series.front();
        if(i%m==0)
        {
            series.pop();
            if(series.empty())
            {
                printf("%d>",a);
                break;
            }
            else
            {
                printf("%d, ",a);
            }
        }
        else
        {
            series.pop();
            series.push(a);
        }
    }
    return 0;
}
