#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int people;
  cin>>people;
  vector<int> tshirt(6);
  for(int i=0;i<6;i++){
    cin>>tshirt[i];
  }
  int t,p;
  cin>>t>>p;
  int sum =0;
  for(int i=0;i<6;i++){
    if(tshirt[i]%t==0){sum+=tshirt[i]/t;}
    else{sum+=(tshirt[i]/t)+1;}
  }
  cout<<sum<<"\n";
  cout<<people/p<<" "<<people%p;
  return 0;
}
