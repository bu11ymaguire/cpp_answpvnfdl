#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> ball(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++)
        {
            ball[j] = c;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ball[i]);
    }
    return 0;
}
