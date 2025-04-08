#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i]; 
    }

    sort(A.begin(),A.end());

    cin >> N;
    int tmp;
    for(int i=1;i<=N;i++){
      cin>>tmp;
      if(binary_search(A.begin(),A.end(),tmp)){
        cout<<"1\n";
      }else{cout<<"0\n";}
    }

    return 0;
}
