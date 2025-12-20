// Practice 9. Max Heap
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;
const char INSERT = 'I';
const char DELETE = 'D';
const char MAXIMUM = 'M';
const int MAX_CAPACITY = 1000;

class MaxHeap {
  // Define member variables 
  int capacity;
  int count;
  int* elements;
  
  // Given the index i of element, return the index of that element's parent in the heap
  int parent(int i) {
    if(i%2==0){
      return (i-1)/2;
    }
    return i/2;
  }
  // Given the index i of element, return the index of that element's left child in the heap
  int left(int i) {
    return 2*i+1;
  }
  // Given the index i of element, return the index of that element's right child in the heap
  int right(int i) {
    return 2*i+2;
  }
  void maxHeapify(int i);
public:
  MaxHeap(int num = MAX_CAPACITY) {
    elements = new int[num];
    count = 0;
    capacity = num;
  }
  ~MaxHeap() {
    delete[] elements;
  }
  
  //Insert a given element elem into the heap
  //If the insertion fails, immediately terminate the program with the error message.
  void insertElement(int);
  // Return the maximum of the heap if it exists
  // Otherwise, terminate program with an error
  int maximum();
  // Delete the maximum from the heap and return the maximum
  // If deletion fails, terminate program with an error
  int deleteMaximum();

  int getCount();
  int getElements(int);
};

void MaxHeap::maxHeapify(int i) 
{
  int largest = i;
  int L = left(i);
  int R = right(i);

  if(L<count && elements[L]>elements[largest]){
    largest = L;
  }

  if(R<count && elements[R]>elements[largest]){
    largest = R;
  }

  if(largest!=i){
    int tmp = elements[i];
    elements[i] = elements[largest];
    elements[largest] = tmp;
    maxHeapify(largest);
  }
}

void MaxHeap::insertElement(int x) {
  if(count==capacity)
  {
    cerr<<"Store is full! Deletion is needed.";
    exit(1);
  }

  int address = count;
  elements[address] = x;
  count++;

  int prnts,tmp;
  while(address!=0){
    prnts = parent(address);
    if(elements[address]<=elements[prnts]){break;}
    tmp = elements[address];
    elements[address] = elements[prnts];
    elements[prnts] = tmp;
    address = prnts;
  }
}

int MaxHeap::maximum() {
  if(count==0){
    cerr<<"Invalid Access.Heap is empty.";
    exit(1);
  }
  else{
    return elements[0];
  }
}

int MaxHeap::deleteMaximum() {
  if(count==0){
    cerr<<"Invalid Access.Heap is empt.";
    exit(1);
  }
  int old_max = elements[0];
  elements[0] = elements[count-1];
  count--;
  maxHeapify(0);
  return old_max;
}

int MaxHeap::getCount(){return count;}

int MaxHeap::getElements(int k){return elements[k];}


int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr<<"Correct usage: [program] [input] [output]"<<endl;
    exit(1);
  }
  MaxHeap h;
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string line;
  while (getline(inFile, line))
  {
    char op = line[0];
    istringstream iss(line.substr(1));
    int key;
    string name;
    cout <<line<<endl;
    switch(op)
    {
      case INSERT:
        if (!(iss >> key)) {
          cerr<<"INSERT: invalid input"<<endl;
          exit(1);
        }
        h.insertElement(key);
        for(int i=0;i<h.getCount();i++){
          outFile<<h.getElements(i)<<' ';
        }
        outFile<<endl;
        break;
      case DELETE:
        h.deleteMaximum();
        for(int i=0;i<h.getCount();i++){
          outFile<<h.getElements(i)<<' ';
        }
        outFile<<endl;
        break;
      case MAXIMUM:
        outFile<<h.maximum()<<endl;
        break;
      default:
        cerr<<"Undefined operator"<<endl;
        exit(1);
    }
  }
  outFile.close();
  inFile.close();
}
