class TreeNode {
public:
  int key;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int k, TreeNode* l=nullptr, TreeNode* r=nullptr) {
    key = k;
    left = l;
    right = r;
  }
};

class BinarySearchTree {
public:
  TreeNode* root;
  BinarySearchTree(): root(nullptr) {}
  ~BinarySearchTree();

  TreeNode* arrayToBST(vector<int>&, int, int);
  // Return true if tree is empty; false otherwise
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
  void _printSpaces(double, TreeNode*);
  void Inorder_Recursive(TreeNode*,ofstream&);
  void Preorder_Recursive(TreeNode*,ofstream&);
  void Postorder_Recursive(TreeNode*,ofstream&);
};

BinarySearchTree::~BinarySearchTree() { //시간복잡도: O(n);
  if(root == nullptr){return;}

  auto Delete =[](TreeNode* node, auto& self){
    if(node == nullptr){return;}
    self(node->left,self);
    self(node->right,self);
    delete node;
  };

  Delete(root,Delete);
  root = nullptr;
}

// Given a sequence arr of integers, start index l, the end index r, 
// build a binary search (sub)tree that contains keys in arr[l], ..., arr[r].
// Return the root node of the tree
TreeNode* BinarySearchTree::arrayToBST(vector<int>& arr, int l, int r) { //시간 복잡도 :O(n)
  if(l>r){return nullptr;}

  for(int i=l;i<r;i++) 
  {
    if(arr[i]>=arr[i+1]){return nullptr;}
  }

  int Middle = (l+r)/2;

  TreeNode* mid = new TreeNode(arr[Middle]);
  mid->left = arrayToBST(arr,l,Middle-1);
  mid->right = arrayToBST(arr,Middle+1,r);
  return mid;
}

// Return the node with the minimum value 
TreeNode* BinarySearchTree::findMin() { // Avg:O(log(n)) , Worst:O(n)
  if(root==nullptr){return nullptr;} 

  TreeNode* current = root;
  for(;current->left!=nullptr;current=current->left){}
  return current;
}

// Return the node with the maximum value 
TreeNode* BinarySearchTree::findMax() { // Avg:O(log(n)) , Worst:O(n)
  if(root==nullptr){return nullptr;} 

  TreeNode* current = root;
  for(;current->right!=nullptr;current=current->right){}

  return current;
}

// Given a query, search for the node whose key is equal to query.
// If the node exists, return the key
// Otherwise, return nullptr
TreeNode* BinarySearchTree::search(int query) { // Avg:O(log(n)) , Worst:O(n)
  if(root == nullptr){return nullptr;}

  TreeNode* current = root;
  for(;current!=nullptr;)
  {
    if(current->key==query){break;}
    else if(current->key>query){current=current->left;}
    else{current=current->right;}
  }
  return current;
}

// If node with key k alreay exists in the tree, do nothing
// Otherwise, insert a new node with key k 
void BinarySearchTree::insertNode(int k) { // Avg:O(log(n)) , Worst:O(n)
  if(search(k)!=nullptr){
    return;
  }
  if(root == nullptr){ root = new TreeNode(k); return;}
  TreeNode* current = root;
  while(true){
    if(k>current->key){
      if(current->right==nullptr)
      {
        current->right = new TreeNode(k);
        break;
      }
      current = current -> right;
    }
    else if(k<current->key){
      if(current->left==nullptr)
      {
        current->left = new TreeNode(k);
        break;
      }
      current = current ->left;
    }
  }
}

// If deletion fails, immediately terminate the program
// Otherwise, delete the node with key k
void BinarySearchTree::deleteNode(int k) // Avg:O(log(n)) , Worst:O(n)
{ 
  if(root == nullptr){
    cerr<<"Error: Tree is Empty."<<endl;
    exit(1);
  } //루트가 nullptr이면 종료

  TreeNode* Target=nullptr;
  TreeNode* Parents;
  bool is_left = false;

  if(root->key == k){Target = root;}
  else
  {
    Parents = root;
    while(true)
    {
      if(Parents->left!=nullptr&&Parents->left->key==k){
        Target = Parents->left;
        is_left = true;
        break;
      }
      else if(Parents->right!=nullptr&&Parents->right->key==k){
        Target = Parents->right;
        is_left = false;
        break;
      }
      else if(Parents->key<k)
      {
        if(Parents->right==nullptr){break;}
        Parents = Parents->right;
      }
      else if(Parents->key>k)
      {
        if(Parents->left==nullptr){break;}
        Parents = Parents->left;
      }
    }
  }

  if(Target==nullptr){
    cerr<<"Delete Failed: Invalid Value"<<endl;
    exit(1);
  } //아직까지 Target이 nullptr이라는 거는 search에 실패했다는 뜻이므로 종료 

  if(Target->left==nullptr&&Target->right==nullptr) //자식이 없는 노드의 삭제
  {
    if(Target==root)
    {
      TreeNode* tmp = root;
      root = nullptr;
      delete tmp;
    }
    else
    {
      if(is_left){Parents->left = nullptr;}
      else{Parents->right = nullptr;}
      delete Target;
    }
  }

  else if( (Target->left!=nullptr&&Target->right==nullptr) || (Target->left==nullptr&&Target->right!=nullptr) ) //자식이 하나있는 노드의 삭제
  {
    if(Target == root)
    {
      if(Target->left==nullptr)
      {
        TreeNode* tmp = root;
        root = root->right;
        delete tmp;
      }
      else{
        TreeNode* tmp = root;
        root = root->left;
        delete tmp;
      }
    }

    else
    {
      if(is_left)
      {
        Parents->left = (Target->left==nullptr) ? Target->right:Target->left;
        delete Target;
      }
      else
      {
        Parents->right = (Target->left==nullptr) ? Target->right:Target->left;
        delete Target;
      }
    }

  }

  else if(Target->left!=nullptr&&Target->right!=nullptr) 
  {
    TreeNode* s_parents= Target;
    TreeNode* success=Target->right;
    while(success->left!=nullptr)
    {
      s_parents = success;
      success = s_parents->left;
    }
    if(Target==root)
    {
      if(success!=Target->right)
      {
        s_parents->left = success->right;
        success->right = Target->right;
      }
      success->left = Target->left;
      delete Target;
      root = success;
    }
    else
    {
      if(success != Target->right){
        s_parents-> left = success->right;
        success-> right = Target->right;
      }
      success->left = Target -> left;

      if(is_left){
        Parents->left = success;
      }
      else
      {
        Parents->right = success;
      }
      delete Target;
    }
  }
}

// Given an output file stream, write the keys of all the nodes 
// visited in inorder traversal
// Every Traversal's Time Complexity is alwas O(n).
void BinarySearchTree::writeInorder(ofstream& outFile) { //O(n)
  Inorder_Recursive(root,outFile);
  outFile<<endl;
}

void BinarySearchTree::Inorder_Recursive(TreeNode* node,ofstream& outFile){
  if(node==nullptr){return;}

  Inorder_Recursive(node->left,outFile);
  outFile<<node->key<<" ";
  Inorder_Recursive(node->right,outFile);
}

// Given an output file stream, write the keys of all the nodes 
// visited in preorder traversal
void BinarySearchTree::writePreorder(ofstream& outFile) {
  Preorder_Recursive(root,outFile);
  outFile<<endl;
}

void BinarySearchTree::Preorder_Recursive(TreeNode* node,ofstream& outFile)
{
  if(node==nullptr){return;}
  outFile<<node->key<<" ";
  Preorder_Recursive(node->left,outFile);
  Preorder_Recursive(node->right,outFile);
}

// Given an output file stream, write the keys of all the nodes 
// visited in postorder traversal
void BinarySearchTree::writePostorder(ofstream& outFile) {
  Postorder_Recursive(root,outFile);
  outFile<<endl;
}

void BinarySearchTree::Postorder_Recursive(TreeNode* node,ofstream& outFile){
  if(node==nullptr){return;}
  Postorder_Recursive(node->left,outFile);
  Postorder_Recursive(node->right,outFile);
  outFile<<node->key<<" ";
}class TreeNode {
public:
  int key;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int k, TreeNode* l=nullptr, TreeNode* r=nullptr) {
    key = k;
    left = l;
    right = r;
  }
};

class BinarySearchTree {
public:
  TreeNode* root;
  BinarySearchTree(): root(nullptr) {}
  ~BinarySearchTree();

  TreeNode* arrayToBST(vector<int>&, int, int);
  // Return true if tree is empty; false otherwise
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
  void _printSpaces(double, TreeNode*);
  void Inorder_Recursive(TreeNode*,ofstream&);
  void Preorder_Recursive(TreeNode*,ofstream&);
  void Postorder_Recursive(TreeNode*,ofstream&);
};

BinarySearchTree::~BinarySearchTree() { //시간복잡도: O(n);
  if(root == nullptr){return;}

  auto Delete =[](TreeNode* node, auto& self){
    if(node == nullptr){return;}
    self(node->left,self);
    self(node->right,self);
    delete node;
  };

  Delete(root,Delete);
  root = nullptr;
}

// Given a sequence arr of integers, start index l, the end index r, 
// build a binary search (sub)tree that contains keys in arr[l], ..., arr[r].
// Return the root node of the tree
TreeNode* BinarySearchTree::arrayToBST(vector<int>& arr, int l, int r) { //시간 복잡도 :O(n)
  if(l>r){return nullptr;}

  for(int i=l;i<r;i++) 
  {
    if(arr[i]>=arr[i+1]){return nullptr;}
  }

  int Middle = (l+r)/2;

  TreeNode* mid = new TreeNode(arr[Middle]);
  mid->left = arrayToBST(arr,l,Middle-1);
  mid->right = arrayToBST(arr,Middle+1,r);
  return mid;
}

// Return the node with the minimum value 
TreeNode* BinarySearchTree::findMin() { // Avg:O(log(n)) , Worst:O(n)
  if(root==nullptr){return nullptr;} 

  TreeNode* current = root;
  for(;current->left!=nullptr;current=current->left){}
  return current;
}

// Return the node with the maximum value 
TreeNode* BinarySearchTree::findMax() { // Avg:O(log(n)) , Worst:O(n)
  if(root==nullptr){return nullptr;} 

  TreeNode* current = root;
  for(;current->right!=nullptr;current=current->right){}

  return current;
}

// Given a query, search for the node whose key is equal to query.
// If the node exists, return the key
// Otherwise, return nullptr
TreeNode* BinarySearchTree::search(int query) { // Avg:O(log(n)) , Worst:O(n)
  if(root == nullptr){return nullptr;}

  TreeNode* current = root;
  for(;current!=nullptr;)
  {
    if(current->key==query){break;}
    else if(current->key>query){current=current->left;}
    else{current=current->right;}
  }
  return current;
}

// If node with key k alreay exists in the tree, do nothing
// Otherwise, insert a new node with key k 
void BinarySearchTree::insertNode(int k) { // Avg:O(log(n)) , Worst:O(n)
  if(search(k)!=nullptr){
    return;
  }
  if(root == nullptr){ root = new TreeNode(k); return;}
  TreeNode* current = root;
  while(true){
    if(k>current->key){
      if(current->right==nullptr)
      {
        current->right = new TreeNode(k);
        break;
      }
      current = current -> right;
    }
    else if(k<current->key){
      if(current->left==nullptr)
      {
        current->left = new TreeNode(k);
        break;
      }
      current = current ->left;
    }
  }
}

// If deletion fails, immediately terminate the program
// Otherwise, delete the node with key k
void BinarySearchTree::deleteNode(int k) // Avg:O(log(n)) , Worst:O(n)
{ 
  if(root == nullptr){
    cerr<<"Error: Tree is Empty."<<endl;
    exit(1);
  } //루트가 nullptr이면 종료

  TreeNode* Target=nullptr;
  TreeNode* Parents;
  bool is_left = false;

  if(root->key == k){Target = root;}
  else
  {
    Parents = root;
    while(true)
    {
      if(Parents->left!=nullptr&&Parents->left->key==k){
        Target = Parents->left;
        is_left = true;
        break;
      }
      else if(Parents->right!=nullptr&&Parents->right->key==k){
        Target = Parents->right;
        is_left = false;
        break;
      }
      else if(Parents->key<k)
      {
        if(Parents->right==nullptr){break;}
        Parents = Parents->right;
      }
      else if(Parents->key>k)
      {
        if(Parents->left==nullptr){break;}
        Parents = Parents->left;
      }
    }
  }

  if(Target==nullptr){
    cerr<<"Delete Failed: Invalid Value"<<endl;
    exit(1);
  } //아직까지 Target이 nullptr이라는 거는 search에 실패했다는 뜻이므로 종료 

  if(Target->left==nullptr&&Target->right==nullptr) //자식이 없는 노드의 삭제
  {
    if(Target==root)
    {
      TreeNode* tmp = root;
      root = nullptr;
      delete tmp;
    }
    else
    {
      if(is_left){Parents->left = nullptr;}
      else{Parents->right = nullptr;}
      delete Target;
    }
  }

  else if( (Target->left!=nullptr&&Target->right==nullptr) || (Target->left==nullptr&&Target->right!=nullptr) ) //자식이 하나있는 노드의 삭제
  {
    if(Target == root)
    {
      if(Target->left==nullptr)
      {
        TreeNode* tmp = root;
        root = root->right;
        delete tmp;
      }
      else{
        TreeNode* tmp = root;
        root = root->left;
        delete tmp;
      }
    }

    else
    {
      if(is_left)
      {
        Parents->left = (Target->left==nullptr) ? Target->right:Target->left;
        delete Target;
      }
      else
      {
        Parents->right = (Target->left==nullptr) ? Target->right:Target->left;
        delete Target;
      }
    }

  }

  else if(Target->left!=nullptr&&Target->right!=nullptr) 
  {
    TreeNode* s_parents= Target;
    TreeNode* success=Target->right;
    while(success->left!=nullptr)
    {
      s_parents = success;
      success = s_parents->left;
    }
    if(Target==root)
    {
      if(success!=Target->right)
      {
        s_parents->left = success->right;
        success->right = Target->right;
      }
      success->left = Target->left;
      delete Target;
      root = success;
    }
    else
    {
      if(success != Target->right){
        s_parents-> left = success->right;
        success-> right = Target->right;
      }
      success->left = Target -> left;

      if(is_left){
        Parents->left = success;
      }
      else
      {
        Parents->right = success;
      }
      delete Target;
    }
  }
}

// Given an output file stream, write the keys of all the nodes 
// visited in inorder traversal
// Every Traversal's Time Complexity is alwas O(n).
void BinarySearchTree::writeInorder(ofstream& outFile) { //O(n)
  Inorder_Recursive(root,outFile);
  outFile<<endl;
}

void BinarySearchTree::Inorder_Recursive(TreeNode* node,ofstream& outFile){
  if(node==nullptr){return;}

  Inorder_Recursive(node->left,outFile);
  outFile<<node->key<<" ";
  Inorder_Recursive(node->right,outFile);
}

// Given an output file stream, write the keys of all the nodes 
// visited in preorder traversal
void BinarySearchTree::writePreorder(ofstream& outFile) {
  Preorder_Recursive(root,outFile);
  outFile<<endl;
}

void BinarySearchTree::Preorder_Recursive(TreeNode* node,ofstream& outFile)
{
  if(node==nullptr){return;}
  outFile<<node->key<<" ";
  Preorder_Recursive(node->left,outFile);
  Preorder_Recursive(node->right,outFile);
}

// Given an output file stream, write the keys of all the nodes 
// visited in postorder traversal
void BinarySearchTree::writePostorder(ofstream& outFile) {
  Postorder_Recursive(root,outFile);
  outFile<<endl;
}

void BinarySearchTree::Postorder_Recursive(TreeNode* node,ofstream& outFile){
  if(node==nullptr){return;}
  Postorder_Recursive(node->left,outFile);
  Postorder_Recursive(node->right,outFile);
  outFile<<node->key<<" ";
}

