#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node (int input): data(input),left(nullptr),right(nullptr) {} 
};

void after_up(Node* In){ //후위
  if(In==nullptr){}
  else{
    after_up(In->left);
    after_up(In->right);
    cout<<In->data<<'\n';
  }
}

void delete_btmemory(Node* In){  //스택을 이용한 후위순회 방식의 메모리 삭제 공부하기
  if(In==nullptr){return;}
  delete_btmemory(In->left);
  delete_btmemory(In->right);
  delete In;
}

Node* buildTree(vector<int>& befor_up, int& index, int n, int min, int max){
  if(index>n){return nullptr;}

  int val = befor_up[index];
  if(val<=min||val>=max) return nullptr;

  Node* root = new Node(val);
  index++;

  root->left = buildTree(befor_up,index,n,min,val);
  root->right = buildTree(befor_up,index,n,val,max);

  return root;
}



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> befor;
  int in;
  while(cin>>in){
    befor.push_back(in);
  }

  int index = 0;
  int number = befor.size() - 1;

  Node* root = buildTree(befor, index, number, 0, 10000000 );

  after_up(root);

  delete_btmemory(root); //메모리 삭제

  return 0;
}
