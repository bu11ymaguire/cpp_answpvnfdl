// Practice 4. Palindromes and Balance
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <stack> // built-in library for stacks
using namespace std;
const char PALINDROME = 'P';
const char BALANCE = 'B';

// Return true if str is a palindrome; false otherwise
bool isPalindrome(string& str)  //시간복잡도 O(n)
{
  vector<char> change;
  for(int i=0;i<str.length();i++)
  {
    char A = (char)str[i];
    if(A>='a'&& A<='z')
    {
        change.push_back(A);
    }
    else if (A>='A'&& A<='Z')
    {
        A+=32; //대문자 변환
        change.push_back(A);
    }
  } //입력받은 문자열에서 알파벳들만 추려내고 모두 소문자로 정리
  stack<char> ballindrope;
  for(int i=0;i<change.size()/2;i++)
  {
    ballindrope.push(change[i]);
  }
  for(int i=change.size()/2+1;i<change.size();i++) 
  {
    if(ballindrope.top() == change[i]) //stack의 탑과 탐색하는 문자열의 문자가 같으면 대칭이므로 pop.
    {
        ballindrope.pop();
    }
    else 
    {
        return false;
    }
  }
  if(ballindrope.empty())
  {
    return true;
  }
  else{
    return false;
  }
}

// Return true if brackets are balanced in str; false otherwise
bool balance(string& str) {  //시간복잡도: O(n)
  stack<char> balance;
  bool check = true;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]=='(') //( ) 괄호 처리 프로토콜
    {
      balance.push('(');
    }
    if(str[i]==')')
    {
      if(!balance.empty()&&balance.top()=='(') // &&사용시 앞쪽에 더 중요한 조건을을 앞쪽에 둔다. 짝을 이루기 위해 balance가 비어있는지 아닌지 확인
      {
        balance.pop();
      }
      else
      {
        check = false;
        break;
      }
    }

    if(str[i]=='{') //{} 괄호 처리 프로토콜 
    {
      balance.push('{');
    }
    if(str[i]=='}')
    {
      if(!balance.empty()&&balance.top()=='{') 
      {
        balance.pop();
      }
      else
      {
        check = false;
        break;;
      }
    }

    if(str[i]=='[') //[ ] 괄호 처리 프로토콜 
    {
      balance.push('[');
    }
    if(str[i]==']')
    {
      if(!balance.empty()&&balance.top()=='[') 
      {
        balance.pop();
      }
      else
      {
        check = false;
        break;;
      }
    }
  }
  if(balance.empty()&&check)
  {
    return true;
  }
  else
  {
    return false;
  }
}
