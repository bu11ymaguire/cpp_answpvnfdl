// Practice 12. Search
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <utility>
using namespace std;
const char BINARY_SEARCH = 'B';
const char PERFECT_SQUARE = 'P';

void check_index(vector<int>& hello, int from, int to, int x, int* index)
{
  if(from>to)
  {
    *index=-1;
    return;
  }
  int middle = (from+to)/2;
  if(hello[middle]==x)
  {
    *index = middle;
    return;
  }else if(hello[middle]>x){
    check_index(hello,from,middle-1,x,index);
  }else if(hello[middle]<x){
    check_index(hello,middle+1,to,x,index);
  }
}

void check_square(vector<int>& integer, int from, int to, int x, int* index )
{
  if(from>to){
    *index = -1;
    return;
  }
  int middle = (from+to)/2;
  long long result = static_cast<long long>(integer[middle] * integer[middle]);
  if(result==x)
  {
    *index = middle;
    return;
  }else if(result>x){
    check_square(integer,from,middle-1,x,index);
  }else if(result<x){
    check_square(integer,middle+1,to,x,index);
  }
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
    int size, x, index;
    switch(op)
    {
      case BINARY_SEARCH:{
        if(!(iss>>size)){
          cerr<<"Error: invalid size"<<endl;
          exit(1);
        }
        if(!(iss>>x)){
          cerr<<"Error: invalid x"<<endl;
          exit(1);
        }

        string second_line;
        if(!getline(inFile,second_line)){
          cerr<<"Error:Invalid Array Line"<<endl;
          exit(1);
        }
        istringstream second_iss(second_line);
        for(int i=0;i<size;i++){
          int num;
          if(!(second_iss>>num)){
            cerr<<"Error: invalid number"<<endl;
            exit(1);
          }
          if(i>0){
            if(num<arr[i-1]){
              cerr<<"Error:Array shoulde be already sorted"<<endl;
              exit(1);
            }
          }
          arr.push_back(num);
        }
        if(size!=arr.size()){
          cerr<<"Error:Array's size is unmatched."<<endl;
          exit(1);
        }
        index = -1;
        check_index(arr,0,arr.size()-1,x,&index);
        outFile<<"B "<<size<<' '<<x<<endl;
        if(index==-1){
          outFile<<'N'<<endl;
        }else{
          outFile<<index<<endl;
        }
        break;
      }
      case PERFECT_SQUARE:{
        if (!(iss >> x)) {
          cerr<<"Error: invalid input"<<endl;
          exit(1);
        }
        if(x<0){
          cerr<<"Error: x should be larger than zero"<<endl;
          exit(1);
        }else if(x==0){
          outFile<<'T'<<endl;
          break;
        }
        vector<int> hello_world(x+1);
        for(int i=0;i<=x;i++){
          hello_world[i]=i;
        }
        index = -1;
        check_square(hello_world,1,x,x,&index);
        if(index==-1){
          outFile<<'F'<<endl;
        }else if(index*index==x){
          outFile<<'T'<<endl;
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
