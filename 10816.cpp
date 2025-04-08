#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int number;
  cin>>number;
  vector<int> plus(10000001,0);
  vector<int> minus(10000001,0);
  for(int i=1;i<=number;i++){
    int in;
    cin>>in;
    if(in>=0){plus[in]+=1;}
    else{
      minus[-in]+=1;
    }
  }
  int search;
  cin>>search;
  for(int i=1;i<=search;i++){
    int in;
    cin>>in;
    if(in>=0){
      cout<<plus[in]<<" ";
    }
    else{cout<<minus[-in]<<" ";}
  }
  return 0;
}
