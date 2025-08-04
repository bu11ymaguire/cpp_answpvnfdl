#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    string maple;
    cin>>maple;
    priority_queue<int,vector<int>,greater<int>> hello_there;
    vector<int> tryig(N+1,0);
    int dd=0;
    for(const char hello: maple)
    {
        if(hello!='D')
        {
            dd++;
        }
    }
    hello_there.push(dd);
    tryig[0] =dd;

    for(int i=0;i<N;i++)
    {
        char current_char = maple[i];
        if(current_char=='D')
        {
            tryig[i+1] = tryig[i]+1; //해당 B를 D로 뒤집을 필요가 없어짐. 그리고 그 이후 영역에 대해서 B/D 판단
        }
        else
        {
            tryig[i+1] = tryig[i]-1; //해당 D를 B로 뒤집어야 됨. 그리고 그 이후 영역에 대해서 B/D 판단
        }
        hello_there.push(tryig[i+1]);
    }

    cout<<hello_there.top();
    return 0;
}
