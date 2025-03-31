#include <iostream>
#include <string>
#include <vector>
#include <deque>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >>n;
    vector<int> input(n+1);
    input[0]=0;
    deque<pair<int,int>> order;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i];
        order.push_back(make_pair(i,input[i]));
    }

    while(!order.empty())
    {
        pair<int,int> current = order.front();
        order.pop_front();
        cout << current.first<<" ";
        int move = current.second;
        if(move>0)
        {
            move --;
            while(move>0&& !order.empty())
            {
                pair<int, int> tmp = order.front();
                order.pop_front();
                order.push_back(tmp);
                move--;
            }
        }
        else if(move<0)
        {
            move = - move;
            while(move>0&&!order.empty())
            {
                auto tmp = order.back();
                order.pop_back();
                order.push_front(tmp);
                move--;
            }
        }
    }
    return 0;
}
