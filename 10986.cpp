#include<iostream>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n,m;
  cin >> n >>m;
  vector<long long> sum(n+1);
  sum[0]=0;
  for(int i=1;i<=n;i++)
  {
    long long in;
    cin>>in;
    sum[i]=sum[i-1]+in;
  }
  vector<long long> rest(m,0); 
  long long result =0;
  for(int i=1;i<=n;i++)
  {
    int remainder = sum[i]%m;
    if(remainder==0)
    {
      result++;
    }
    rest[remainder]++;
  }
  for(int i=0;i<m;i++) //이쪽 부분을 처음에는 이중 반복문을 돌렸다가 시간초과가 떠서 어떻게 해야되는지 몰라서 유튜브에서 저자 해설 강의 찾아봄.
  {
    if(rest[i]>1)
    {
      result += rest[i] * (rest[i]-1)/2; // 나머지가 같은 서로 다른 애들 중에서 2개를 뽑으면 된다.
    }
  }
  cout<<result;
  return 0;
}
