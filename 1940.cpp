#include <iostream>
#include <vector>
using namespace std;
//투포인터를 안 썼는데 그냥 조건이 널널해서 맞음;
int main()
{
  int n; //재료의 개수
  cin>>n;
  int total; //두 재료의 합
  cin>>total;
  vector<int> jaeryo(n+1);
  jaeryo[0]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>jaeryo[i];
  }
  int count =0; 
  int i=1; 
  while(i<n)
  {
    for(int j=i+1;j<=n;j++)
    {
        int sum = jaeryo[i];
        sum += jaeryo[j];
        if(sum==total)
        {
            count++;
        }
    }
    i++;
  }
  cout<<count;
  return 0;
}
