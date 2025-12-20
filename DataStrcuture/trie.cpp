#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
const char BUILD_TRIE = 'T';
const char AUTOCOMPLETE = 'A';
const int CHAR_SIZE = 128; // Contains ASCII codes for a-z & A-Z.

class Trie
{
private:
  class TrieNode
  {
    public:
      bool endsHere;
      TrieNode* children[CHAR_SIZE];

      TrieNode(): endsHere(false){
        for(int i =0 ; i<CHAR_SIZE ; ++i)
        {
          children[i] = nullptr;        
        }
      }

      ~TrieNode() {
        for(int i=0 ; i<CHAR_SIZE ; ++i){
          delete children[i];
        }
      }
      
      void insert(const char* word){
        TrieNode * current = this;
        for (int i = 0;word[i]!='\0'; ++i){
          int index = word[i];
          
          if (!current->children[index]){
            current -> children[index] = new TrieNode();
          }
          current = current->children[index];
        }
        current->endsHere = true;
      }

      bool search(const char* word)
      {
        TrieNode * current = this;

        for(int i = 0; word[i]!='\0';++i){
          int index = word[i];

          if(!current->children[index]){
            return false;
          }
          current = current ->children[index];
        }
        return current->endsHere;
      }

      void autoComplete(string brefix, vector<string> &result){

        if(this->endsHere)
        {
          result.push_back(brefix);
        }

        for(int i=0;i<CHAR_SIZE;++i)
        {
          if(this->children[i]){
            this->children[i]->autoComplete(brefix+(char)i,result);
          }
        }
      }
  };

  TrieNode* root;

public:
  Trie(){
    root = new TrieNode();
  }
  
  ~Trie(){
    delete root;
  }

  void insert(string& word){
    root->insert(word.c_str());
  }
  
  bool search(string& word) {
    return root->search(word.c_str());
  }

  TrieNode* searchNode(const string& prefix)
  {
    TrieNode* current = root;
    for(char ch : prefix)
    {
      int index = ch;
      if(!current->children[index]){
        return nullptr;
      }
      current = current->children[index];
    }
    return current;
  }

  vector<string> getResult(const string& prefix){
    vector<string> results;

    TrieNode* prefixNode = searchNode(prefix);

    if(prefixNode){
      prefixNode->autoComplete(prefix,results);
    }

    sort(results.begin(),results.end());
    return results;
  }
};


int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr<<"Correct usage: [program] [input] [output]"<<endl;
    exit(1);
  }
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string line;
  Trie Christmas;
  while (getline(inFile, line))
  {
    char op = line[0];
    istringstream iss(line.substr(2));
    vector<string> words;
    string prefix;
    int n;
    switch(op)
    {
      case BUILD_TRIE:{
        if (!(iss >> n)) {
          cerr<<"BUILD_TRIE: invalid input"<<endl;
          exit(1);
        }
        for (int i = 0; i < n; ++i) {
          if (!getline(inFile, line)) {
            cerr<<"BUILD_TRIE: invalid input"<<endl;
            exit(1);
          }
          words.push_back(line);
        }
        for(string& word:words){
          Christmas.insert(word);
        }
        break;
      }         
      case AUTOCOMPLETE:{
        if (!(iss >> prefix)) {
          cerr<<"AUTOCOMPLETE: invalid input"<<endl;
          exit(1);
        }
        vector<string> hello = Christmas.getResult(prefix);
        if(hello.size()==0)
        {
          outFile<<"Empyt"<<endl;
        }else
        {
          for(string& word:hello)
          {
            outFile<<word<<' ';
          }
          outFile<<endl;
        }
        break;
      }
      default:
        cerr<<"Undefined operator"<<endl;
        exit(1);
    }
  }
  outFile.close();
  inFile.close();
}
