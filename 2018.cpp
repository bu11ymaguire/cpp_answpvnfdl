#include <iostream>
using namespace std;

int  main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  int count =1; //자기 자신(n)이 더해지는 경우우
  int i=1; //첫 start point는 1
  while(i<n)
  {
    int sum=0;
    for(int j=i;sum<n;j++) // start 포인트부터 end포인트까지 더해서 n보다 커지면 반복문 종료
    {
        sum+=j;
        if(sum==n)
        {
            count++; // 합이 정확히 n이면 카운트를 하나 세고 반복문 종료 
            break;
        }
    }
    i++; //반복문이 종료되면 start 포인트를 하나 증가시킴
  }
  cout<<count;
  return 0;
}
