#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r,c;
    cin >>r >> c;
    vector<string> hello(r);

    for(int i = 0; i <r; i++)
    {
        cin >> hello[i];
    }

    int count = 0;

    int L = 0;
    int R = c-1;

    while(L<=R)
    {
        int mid = (L + R) / 2;
        unordered_set<string> us;
        bool duplicated = false;

        for(int column = 0; column < c ; column++)
        {
            string input = "";
            for(int row = mid+1; row < r; row++)
            {
                input += hello[row][column];
            }

            if(us.find(input)!=us.end())
            {
                duplicated = true;
                break;
            }
            us.insert(input);
        }

        if(duplicated)
        {
            R = mid - 1;
        }else
        {
            count = mid+1; //0-base 기반 보정
            L = mid + 1;
        }
    }
    cout << count;
    return 0;
}
