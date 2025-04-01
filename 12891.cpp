#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    string input;
    cin>>input;

    vector<int> need(4);
    for (int i = 0; i < 4; i++) {
        cin >> need[i]; // A, C, G, T 순서
    }

    vector<int> kase(4, 0); //최초 탐색
    for (int i = 0; i < m; i++) 
    {
        if (input[i] == 'A') kase[0]++;
        else if (input[i] == 'C') kase[1]++;
        else if (input[i] == 'G') kase[2]++;
        else if (input[i] == 'T') kase[3]++;
    }

    int possible = 0;
    bool valid = true;
    for (int j = 0; j < 4; j++) {   //조건: need에서 요구하는 조건 '이상'이면 충족되는 암호
        if (kase[j] < need[j]) {
            valid = false;
            break;
        }
    }
    if (valid) {
        possible++;
    }

    int last;

    for (int i =1;i<=n-m;i++)
    {
        //기존의 맨 앞의 데이터를 지우고
        if (input[i-1] == 'A') kase[0]--;
        else if (input[i-1] == 'C') kase[1]--;
        else if (input[i-1] == 'G') kase[2]--;
        else if (input[i-1] == 'T') kase[3]--;

        last = i + m -1;

        //맨 뒤의 데이터를 새로 넣고 
        if (input[last] == 'A') kase[0]++;
        else if (input[last] == 'C') kase[1]++;
        else if (input[last] == 'G') kase[2]++;
        else if (input[last] == 'T') kase[3]++;

        valid = true; //디폴트 값은 True
        for (int j = 0; j < 4; j++) {   //조건: need에서 요구하는 조건 '이상'이면 충족되는 암호
            if (kase[j] < need[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            possible++;
        }
    }
    cout << possible;
    return 0;
}
