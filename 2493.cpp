#include<iostream>
#include<vector>
#include<stack>

using namespace std;
//변수가 많을떄는 확실하게 관리하기

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;
  vector<int> number(n+1,0); //입력받기
  for(int i=1;i<=n;i++)
  {
    int tmp;
    cin>> tmp;
    number[i] = tmp;
  }

  vector<int> recieve(n+1,0);
  stack<int> index;

  for(int i=1;i<=n;i++)
  {
    while(!index.empty()&&(number[index.top()]<number[i])) //현재 탑에서 가장 가까운 탑의 인덱스를 저장해줌줌
    {
      index.pop();
    }

    if(!index.empty()){recieve[i]=index.top();}

    index.push(i);
  }

  for(int i=1;i<=n;i++)
  {
    cout<<recieve[i]<<" ";
  }

  return 0;
  }
