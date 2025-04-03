#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n,m;
  cin>>n>>m;
  vector<int> prime_check(m+1,0);
  prime_check[0]=1;
  prime_check[1]=1;
  for(int i=2;i<=m;i++)
  {
    if(prime_check[i]==1)
    {
      continue;
    }
    else if(prime_check[i]==0)
    {
      bool check = true;
      for(int j=2;j<=sqrt(i);j++)
      {
        if(i%j==0)
        {
          check = false;
          break;
        }
      }
      if(!check)
      {
        prime_check[i]=1;
      }
      else if(check&&i>=n)
      {
        cout <<i<<'\n';  
      }
      for(int j=2;j*i<=m;j++)
      {
        prime_check[j*i]=1;
      }
    }
  }

  return 0;
}
