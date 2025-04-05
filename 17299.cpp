#include<iostream>
#include<algorithm>
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
  int max=0;
  vector<int> number(n+1,0); //숫자를 입력받을 벡터
  for(int i=1;i<=n;i++)
  {
    int tmp;
    cin>>tmp;
    if(tmp>=max)
    {
      max = tmp;
    }
    number[i]=tmp;
  }

  vector<int> time(max+1,0); //각 숫자가 얼마나 출력되었는지 확인할 벡터는 입력받은 값들 중 최댓값+1(인덱스 보정)만큼
  for(int i=1;i<=n;i++)
  {
    int check = number[i];
    time[check]=time[check]+1;
  }

  stack<int> adebayor; //단조스택의 핵심은 역주행행
  vector<int> ngf(n+1,-1); //ngf값의 디폴트는 -1

  for(int i=1;i<=n;i++)
  {
    while(!adebayor.empty()&&time[number[adebayor.top()]]<time[number[i]]) /*
    아데바요르 top의 대응되는 인덱스에 대한 number의 호출횟수가 현재 인덱스에 대한 호출횟수보다 작은 경우
    현재 인덱스에 대응되는 number를 NGF에 저장 
    */
    {
      ngf[adebayor.top()]=number[i];
      adebayor.pop(); // 다음 값을 위해 현재 top은 pop.
    }
    adebayor.push(i); //인덱스를 아데바요르 대기열에 push
  }

  for(int i=1;i<=n;i++){
    cout<<ngf[i]<<" ";
  }

  return 0;
  }
