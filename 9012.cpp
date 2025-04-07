#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<string> balance(n);
  for(int i=0;i<n;i++){
    cin>>balance[i];
  }

  for(int i=0;i<n;i++)
  {
    stack<char> perfectly;
    bool chack = true;
    string A = balance[i];
    for(int j=0;j<A.length();j++)
    {
      if(A[j]=='('){perfectly.push('(');}
      else if(A[j]==')'){
        if(perfectly.empty()){chack = false; break;}
        perfectly.pop();
      }
    }
    if(chack&&perfectly.empty()){
      cout<<"YES\n";
    }
    else{cout<<"NO\n";}
  }

  return 0;
}
