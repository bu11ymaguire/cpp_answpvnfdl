#include<iostream>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;
    cin>>N;

    unordered_map<int,set<int>> problem;
    unordered_map<int,int> info; 
    unordered_set<int> diff;
    priority_queue<int> hard;
    priority_queue<int,vector<int>,greater<int>> easy;

    for(int i=0;i<N;i++)
    {
        int number,difficult;
        cin>>number>>difficult;

        if(diff.find(difficult)==diff.end())
        {
            diff.insert(difficult);
            hard.push(difficult);
            easy.push(difficult);
        }

        info[number] = difficult;
        problem[difficult].insert(number);
    }

    int command;
    cin>>command;

    for(int i=0;i<command;i++)
    {
        string input;
        cin>>input;
        if(input=="add")
        {
            int number,difficult;
            cin>>number>>difficult;
            if(diff.find(difficult)==diff.end())
            {
            diff.insert(difficult);
            hard.push(difficult);
            easy.push(difficult);
            }
            info[number] = difficult;
            problem[difficult].insert(number);
        }
        else if(input=="recommend")
        {
            int num;
            cin>>num;
            if(num==1)
            {
                while(!hard.empty()&&problem[hard.top()].empty()){
                    hard.pop();
                }
                cout<< *problem[hard.top()].rbegin()<<'\n';
            }
            else if(num==-1)
            {
               while(!easy.empty()&&problem[easy.top()].empty()){
                   easy.pop();
               }
               cout<<*problem[easy.top()].begin()<<'\n';
            }
        }else if(input=="solved")
        {
            int number;
            cin>>number;
            int differ = info[number];
            problem[differ].erase(number);
        }
    }
    return 0;
}
