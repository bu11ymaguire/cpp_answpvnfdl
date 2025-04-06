#include<iostream>
#include<stack>
using namespace std;

struct Node{
  char data;
  Node* left;
  Node* right;
  Node (char input): data(input),left(nullptr),right(nullptr) {} 
};


void before_up(Node* In){ //전위
  if(In==nullptr){}
  else{
    cout<<In->data;
    before_up(In->left);
    before_up(In->right);
  }
}

void middle_up(Node* In){ //중위
  if(In==nullptr){}
  else{
    middle_up(In->left);
    cout<<In->data;
    middle_up(In->right);
  }
}

void after_up(Node* In){ //후위
  if(In==nullptr){}
  else{
    after_up(In->left);
    after_up(In->right);
    cout<<In->data;
  }
}

void delete_btmemory(Node* In){  //스택을 이용한 후위순회 방식의 메모리 삭제 공부하기
  if(In==nullptr){}
  else{
    delete_btmemory(In->left);
    delete_btmemory(In->right);
    delete In;
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int number;
  cin>>number;

  Node* node[26];
  for(int i=0;i<26;i++){
    node[i]=nullptr;
  }

  int index;

  for(int i=1;i<=number;i++){
    char root,left,right;
    cin>>root>>left>>right;
    index = root-'A';

    if(node[index]==nullptr){ //새로운 노드 생성성
      node[index] = new Node(root);
    }

    if(left!='.')
    {
      int left_idx = left-'A';
      node[left_idx] = new Node(left);
      node[index]->left = node[left_idx];
    }

    if(right!='.')
    {
      int right_idx = right-'A';
      node[right_idx] = new Node(right);
      node[index]->right = node[right_idx];
    }
  }
  before_up(node[0]);
  cout<<'\n';
  middle_up(node[0]);
  cout<<'\n';
  after_up(node[0]);
  
  //메모리 삭제
  delete_btmemory(node[0]);
  //배열 초기화 습관들이기
  for(int i=0;i<26;i++){
    node[i]=nullptr;
  }

  return 0;
}
