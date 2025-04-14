//pratice AVL Skeleton Code _Made By ChatGPT
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const char BUILD = 'B';
const char FIND_MIN = 'm';
const char FIND_MAX = 'M';
const char SEARCH = 'S';
const char INSERT = 'I';
const char DELETE = 'D';
const char INORDER = 'N';
const char PREORDER = 'R';
const char POSTORDER = 'O';

class TreeNode {
public:
  int key;
  int height;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int k, TreeNode* l = nullptr, TreeNode* r = nullptr)
    : key(k), height(1), left(l), right(r) {}
};

class AVLTree {
public:
  TreeNode* root;
  AVLTree() : root(nullptr) {}
  ~AVLTree();

  TreeNode* arrayToAVL(vector<int>&, int, int);  
  bool isEmpty() { return (root == nullptr); }
  TreeNode* findMin();
  TreeNode* findMax();
  TreeNode* search(int);
  void insertNode(int);
  void deleteNode(int);
  void writeInorder(ofstream&);
  void writePreorder(ofstream&);
  void writePostorder(ofstream&);
  void printTree();
private:
  int _getHeight(TreeNode*);
  int _getBalance(TreeNode*);
  TreeNode* _rotateLeft(TreeNode*);
  TreeNode* _rotateRight(TreeNode*);
  TreeNode* _balance(TreeNode*);
  void _printSpaces(double, TreeNode*);
};

// ---------- Implementation Skeleton Below ----------

AVLTree::~AVLTree() {
  if(root==nullptr){return;}

  auto Delete = [](TreeNode* node,auto& self){
    if(node==nullptr){return;}
    self(node->left,self);
    self(node->right,self);
    delete node;
  };

  Delete(root,Delete);
  root = nullptr;
}

// Given sorted array arr[l..r], build a balanced AVL tree
TreeNode* AVLTree::arrayToAVL(vector<int>& arr, int l, int r) {
  if(l>r){return nullptr;}
  
  int mid = l + (r-l)/2;
  TreeNode * node = new TreeNode(arr[mid]);

  node->left = arrayToAVL(arr,l,mid-1);
  node->right = arrayToAVL(arr,mid+1,r);

  node->height = 1 + max(_getHeight(node->left),_getHeight(node->right));
  
  return node;
}

TreeNode* AVLTree::findMin() {
  if(root==nullptr){return nullptr;}
  TreeNode* node = root;
  while(node->left!=nullptr){
    node = node->left;
  }
  return node;
}

TreeNode* AVLTree::findMax() {
  if(root==nullptr){return nullptr;}
  TreeNode* node = root;
  while(node->right!=nullptr){
    node = node->right;
  }
  return node;
}

TreeNode* AVLTree::search(int query) {
  if(root==nullptr){return nullptr;}
  TreeNode* node = root;
  while(node!=nullptr)
  {
    if(node->key==query)break;
    else if(node->key<query)node=node->right;
    else if(node->key>query)node=node->left;
  }
  return node;
}

void AVLTree::insertNode(int k) 
{
  
  if(search((k))!=nullptr){exit(1);}
  if(root==nullptr)
  {
    TreeNode* node = new TreeNode(k);
    node->height = 1;
    root = node;
  }
  else
  {
    TreeNode* node = root;
    while(true)
    {
      if(node->key<k)
      {
        if(node->right==nullptr)
        {
          node->right = new TreeNode(k);
          (node->right)->height = 1;
          break;
        }
        else
        {
          node = node->right;
        }
      }
      else{
        if(node->left==nullptr)
        {
          node->left = new TreeNode(k);
          (node->left)->height = 1;
          break;
        }
        else
        {
          node = node->left;  
        }
      }
    }
  }
}

void AVLTree::deleteNode(int k) {
  // TODO. Practice 7
}

void AVLTree::writeInorder(ofstream& outFile) {
  // Practice 6
}

void AVLTree::writePreorder(ofstream& outFile) {
  // Practice 6
}

void AVLTree::writePostorder(ofstream& outFile) {
  // Practice 6
}

int AVLTree::_getHeight(TreeNode* curr) {
  return curr ? curr->height : 0;
}

int AVLTree::_getBalance(TreeNode* curr) {
  return curr ? _getHeight(curr->left) - _getHeight(curr->right) : 0;
}

TreeNode* AVLTree::_rotateLeft(TreeNode* x) 
{
  if(root==nullptr){return nullptr;}
  TreeNode* parents = root;
  bool is_left = false;
  while(true)
  {
    if((parents->key)<(x->key))
    {
      if(parents->right==x)
      {
        is_left = false;
        break;
      }
      else{parents = parents->right;}
    }
    else if((parents->key)>(x->key))
    {
      if(parents->left==x){
        is_left = true;
        break;
      }
      else{parents = parents->left;}
    }
  }
  if(is_left)
  {
    TreeNode* tmp = x->right;
    x->right = tmp->left;
    parents->left = tmp;
    tmp-> left = x;
  }
  else{
    TreeNode* tmp = x->right;
    x->right = tmp->left;
    parents->right = tmp;
    tmp->left = x;
  }
}

TreeNode* AVLTree::_rotateRight(TreeNode* y) {
  // TODO. Practice 7
}

TreeNode* AVLTree::_balance(TreeNode* node) {
  // TODO. Practice 7
}

void AVLTree::_printSpaces(double n, TreeNode* curr) {
  for (double i = 0; i < n; ++i)
    cout << "  ";
  if (curr == nullptr)
    cout << " ";
  else
    cout << curr->key;
}

void AVLTree::printTree() {
  if (root == nullptr)
    return;
  queue<TreeNode*> q;
  q.push(root);
  queue<TreeNode*> temp;
  int cnt = 0;
  int height = _getHeight(root) - 1;
  double nMaxNodes = pow(2, height + 1) - 1;
  while (cnt <= height) {
    TreeNode* curr = q.front();
    q.pop();
    if (temp.empty())
      _printSpaces(nMaxNodes / pow(2, cnt + 1) + height - cnt, curr);
    else
      _printSpaces(nMaxNodes / pow(2, cnt), curr);
    if (curr == nullptr) {
      temp.push(nullptr);
      temp.push(nullptr);
    }
    else {
      temp.push(curr->left);
      temp.push(curr->right);
    }
    if (q.empty()) {
      cout << endl << endl;
      q = temp;
      queue<TreeNode*> empty;
      swap(temp, empty);
      ++cnt;
    }
  }
}

// ---------- main ----------

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "Correct usage: [exe] [input] [output]" << endl;
    exit(1);
  }

  AVLTree tree;
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string line;

  while (getline(inFile, line)) {
    char op = line[0];
    istringstream iss(line.substr(1));
    int k;
    TreeNode* found = nullptr;
    vector<int> data;

    switch (op) {
    case BUILD:
      while (iss >> k)
        data.push_back(k);
      tree.root = tree.arrayToAVL(data, 0, data.size() - 1);
      if (tree.root) {
        outFile << BUILD << endl;
      } else {
        cerr << "BUILD: invalid input" << endl;
        exit(1);
      }
      tree.printTree();
      break;
    case FIND_MIN:
      found = tree.findMin();
      if (found == nullptr) {
        cerr << "FindMin failed" << endl;
        exit(1);
      } else {
        outFile << found->key << endl;
      }
      break;
    case FIND_MAX:
      found = tree.findMax();
      if (found == nullptr) {
        cerr << "FindMax failed" << endl;
        exit(1);
      } else {
        outFile << found->key << endl;
      }
      break;
    case SEARCH:
      if (!(iss >> k)) {
        cerr << "SEARCH: invalid input" << endl;
        exit(1);
      }
      // Practice 6. Call the function for search
      break;
    case INORDER:
      // Practice 6. Call the function for inorder traversal
      break;
    case PREORDER:
      // Practice 6. Call the function for preorder traversal
      break;
    case POSTORDER:
      // Practice 6. Call the function for postorder traversal
      break;
    case INSERT:
      if (!(iss >> k)) {
        cerr << "INSERT: invalid input" << endl;
        exit(1);
      }
      // TODO. Practice 7. Call the function for insertion
      break;
    case DELETE:
      if (!(iss >> k)) {
        cerr << "DELETE: invalid input" << endl;
        exit(1);
      }
      // TODO. Practice 7. Call the function for deletion
      break;
    default:
      cerr << "Undefined operator" << endl;
      exit(1);
    }
  }

  outFile.close();
  inFile.close();
}
