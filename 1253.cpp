#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
//투포인터를 안써서 조건이 타이트해지니까 뽀록남;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; //원소의 갯수
  cin >> n;
  vector<int> yeah(n+1);
  yeah[0]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>yeah[i];
  }
  sort(yeah.begin()+1,yeah.end()); //이거 처음 써봄;
  /*
  내가 처음에 짬(O(N^3)) : 투포인터의 전제조건(배열이 정렬되어있다고 가정을 숙지하지 못했음)
   for(int i=1;i<=n;i++)
  {
    int target = yeah[i];
    int check_1 =0;
    for(int j=1;j<n;j++)
    {
      int check_2 = 0;
      if(yeah[j]>=target)
      {
        continue;
      }
      else
      {
        int end = j+1;
        for(end;end<=n;end++)
        {
          if(yeah[end]>=target)
          {
            continue;
          }
          else
          {
            if(yeah[j]+yeah[end]==target)
            {
              check_2++;
              break;;
            }
          }
        }  
      }
      if(check_2==1){
        check_1++;
        break;
      }  
    }
    if(check_1==1)
      {
        count++;
        continue;;
      }
  }
  cout << count;
  */
 int count = 0;
 for(int i=1;i<=n;i++)
 {
  int target = yeah[i];
  int left =1, right = n;
  bool check = false;
  while(left<right)
  {
    if(left == i)
    {
      left++;
      continue;
    }
    if(right == i)
    {
      right--;
      continue;
    }
    int sum = yeah[left] + yeah[right];
    if(sum == target)
    {
      check = true;
      break;
    }
    else if(sum<target)
    {
      left++;
      continue;
    }
    else
    {
      right--;
      continue;
    }
  }
  if(check)
  {
    count++;
    continue;
  }
 }
 cout<<count;
 return 0;
}
