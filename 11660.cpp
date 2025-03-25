#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> sum(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int in;
            cin>>in;
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+in;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y,X,Y;
        cin >>x>>y>>X>>Y;
        int sam = sum[X][Y]-sum[x-1][Y]-sum[X][y-1]+sum[x-1][y-1];
        printf("%d\n",sam); //아니 이거왜 시간초과 뜨노 ㅋㅋㅋ
    }
    return 0;
}
