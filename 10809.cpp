#include<iostream> 
#include<string> 
#include<vector> 

using namespace std;
int main() 
{ 
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);
  string word; cin>>word;
  vector<int> check(27,-1);
  for(int i=0;i<word.size();i++)
  { 
    int a = word[i]-'a'+1; if(check[a]==-1) { check[a]=i; }  
  }
  for(int i=1;i<=26;i++)
  { cout<<check[i]<<" "; 
  }
  return 0; 
}
