#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n,L;
  cin>>n>>L;

  vector<int> in(n+1,0); //일단 순서대로 저장
  for(int i=1;i<=n;i++)
  {
    int number;
    cin>>number;
    in[i]=number;
  }

  vector<int> Min;
  int mini;

  deque<pair<int,int>> waiting; // 값, 인덱스를 저장하는 순서쌍의 덱


  for(int i=1;i<=n;i++)
  {
    if(i<=L)
    {
      if(i==1)
      {
        mini=in[i];
      }
      else
      {
        if(mini>in[i]){mini=in[i];}
      }
      while(!waiting.empty()) //최솟값이 오름차순에 오도록
      {
        if(waiting.back().first>=in[i]){waiting.pop_back();}
        else{break;}
      }
      waiting.push_back({in[i],i});
      Min.push_back(mini);
    }
    else
    {
      while(!waiting.empty()) //부분에서 벗어나는 부분 제거
      {
        if(waiting.front().second<=i-L){waiting.pop_front();}
        else{break;}
      }
      while(!waiting.empty()) //단조성 유지
      {
        if(waiting.back().first>=in[i]){waiting.pop_back();}
        else{break;}
      }
      waiting.push_back({in[i],i});
      Min.push_back(waiting.front().first);
    }
  }
    
  for(int i=0;i<n;i++){
    cout<<Min[i]<<" ";
  }

  return 0;
  }
