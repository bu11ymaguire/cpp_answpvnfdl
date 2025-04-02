#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;
  vector<int> chack(n+1,0);
  bool check = true;
  stack<int> ss;
  queue<char> story;
  int last=1; //갱신
  for(int i=1;i<=n;i++)
  {
    int input;
    cin>>input;
    for(int j=last;j<=input;j++)
    {
      if(chack[j]==0)
      {
        ss.push(j);
        chack[j]=1;
        story.push('+');
      }
      else
      {
        continue;
      }
    }
    last = input+1;
    if(ss.top()==input)
    {
      ss.pop();
      story.push('-');
    }
    else
    {
      check = false;
      break;
    }
  }
  if(check)
  {
    while(!story.empty())
    {
      cout<<story.front()<<'\n';
      story.pop();
    }
  }
  else{
    cout<<"NO";
  }
  return 0;
}
