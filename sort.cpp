#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
const char MERGE_SORT = 'M';
const char QUICK_SORT = 'Q';

void merge(vector<int>& target,int from, int mid, int to)
{
  vector<int> copy;
  int left = from;
  int right = mid+1;
  while(copy.size()<to-from+1)
  {
    if(left<=mid&&right<=to)
    {
      if(target[left]>=target[right])
      {
        copy.push_back(target[left]);
        left++;
      }else if(target[left]<target[right]){
        copy.push_back(target[right]);
        right++;
      }
    }else if(left<=mid){
      copy.push_back(target[left]);
      left++;
    }else if(right<=to){
      copy.push_back(target[right]);
      right++;
    }
  }
  for(int i=0;i<to-from+1;i++){
    target[from+i]= copy[i];
  }
}

void merge_sort(vector<int>& target, int from, int to)
{
  if(from>=to){return;}
  int mid = from + (to-from)/2;
  merge_sort(target,from,mid);
  merge_sort(target,mid+1,to);
  merge(target,from,mid,to);
}

int pivot_index(vector<int>&target, int from, int to)
{
  int standard = target[to];
  int start = from-1;
  int tmp;
  for(int i=from;i<to;i++)
  {
    if(target[i]>=standard)
    {
      start++;
      tmp = target[start];
      target[start] = target[i];
      target[i] = tmp;
    }
  }
  start++;
  tmp = target[start];
  target[start] = standard;
  target[to] = tmp;
  return start;
}

void quick_sort(vector<int>&target, int from, int to)
{
  if(from>=to)
  {
    return;
  }
  int base = pivot_index(target,from,to);

  quick_sort(target,from,base-1);
  quick_sort(target,base+1,to);
}

int readInput(ifstream& inFile, istringstream& iss, vector<int>& input) {
  string line;
  int numInput, val;
  input.clear();
  if (!(iss >> numInput)) {
    cerr<<"Error: invalid number of input"<<endl;
    exit(1);
  }
  if (!getline(inFile, line)) {
    cerr<<"Error: unable to read a line"<<endl;
    exit(1);
  }
  istringstream viss(line);
  for (int i = 0; i < numInput; ++i) {
    if (!(viss >> val)) {
      cerr<<"Error: invalid input value"<<endl;
      exit(1);
    }
    else {
      input.push_back(val);
    }
  }
  return numInput;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr<<"Correct usage: [program] [input] [output]"<<endl;
    exit(1);
  }
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string line;
  while (getline(inFile, line))
  {
    char op = line[0];
    istringstream iss(line.substr(2));
    vector<int> arr;
    int size;
    int* tempArray;
    // cout <<line<<endl;
    size = readInput(inFile, iss, arr);
    switch(op)
    {
      case MERGE_SORT:
        merge_sort(arr,0,arr.size()-1);
        for(int i=0;i<arr.size();i++){
          outFile<<arr[i]<<' ';
        }
        outFile<<endl;
        break;
      case QUICK_SORT:
        quick_sort(arr,0,arr.size()-1);
        for(int i=0;i<arr.size();i++){
          outFile<<arr[i]<<' ';
        }
        outFile<<endl;
        break;
      default:
        cerr<<"Undefined operator"<<endl;
        exit(1);
    }
  }
  outFile.close();
  inFile.close();
}
