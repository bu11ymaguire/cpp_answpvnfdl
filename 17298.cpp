#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;
  vector<int> number(n+1,0);
  vector<int> nge(n+1,-1);
  for(int i=1;i<=n;i++)
  {
    int tmp;
    cin>>tmp;
    number[i]=tmp;
  }

  stack<int> adebayor; //쌓아둔 다음 위에서부터 역주행
  for(int i=1;i<=n;i++)
  {
    while(!adebayor.empty()&&(number[adebayor.top()]<number[i]))
    {
      nge[adebayor.top()]=number[i];
      adebayor.pop();

    }
    adebayor.push(i);
  }

  for(int i=1;i<=n;i++){cout<<nge[i]<<" ";}

  return 0;
  }
