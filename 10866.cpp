#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int order;
    cin >> order;

    deque<int> pratice;
    for(int i = 1; i <= order; i++)
    {
        string menu;
        cin >> menu;

        if(menu == "push_back")
        {
            int x;
            cin >> x;
            pratice.push_back(x);
        }
        if(menu == "push_front")
        {
            int y;
            cin >> y;
            pratice.push_front(y);
        }
        if(menu == "pop_front")  // 오타 수정
        {
            if(pratice.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << pratice.front() << endl;
                pratice.pop_front();
            }
        }
        if(menu == "pop_back")
        {
            if(pratice.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << pratice.back() << endl;
                pratice.pop_back();
            }
        }
        if(menu == "size")
        {
            cout << pratice.size() << endl;
        }
        if(menu == "empty")
        {
            cout << pratice.empty() << endl;
        }
        if(menu == "front")
        {
            if(pratice.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << pratice.front() << endl;
            }
        }
        if(menu == "back")
        {
            if(pratice.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << pratice.back() << endl;
            }
        }
    }
    return 0;
}
