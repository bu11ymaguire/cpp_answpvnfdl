#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        string command;
        deque<int> array;
        int size;
        string input;
        
        cin >> command;
        cin >> size;
        cin >> input;
        
        bool check = false;
        bool rev = false;
        
        if(size == 0) {
            if(input != "[]") { 
                cout << "error\n";
                continue;
            }

        } else {
            input = input.substr(1, input.size() - 2); 
            istringstream iss(input);
            string token;
            int count = 0;
            
            while(getline(iss, token, ',')) {
                array.push_back(stoi(token)); 
                count++;
            }
            
            if(count != size) { 
                cout << "error\n";
                continue;
            }
        }
        
        for(int j = 0; j < command.size(); j++)
        {
            if(command[j] == 'D')
            {
                if(array.empty())
                {
                    cout << "error\n";
                    check = false;
                    break;
                }
                if(rev)
                {
                    array.pop_back();
                    check = true;
                }
                else
                {
                    array.pop_front();
                    check = true;
                }
            }
            else if(command[j] == 'R')
            {
                rev = !rev;
                check = true;
            }
        }
        
        if(check == true)
        {
            if(rev)
            {
                reverse(array.begin(),array.end());
            }
            
            cout << '[';
            while(!array.empty())
            {
                if(array.size() == 1)
                {
                    cout << array.front();
                    array.pop_front();
                }
                else
                {
                    cout << array.front() << ',';
                    array.pop_front();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
