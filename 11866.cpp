#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

   
    while (!q.empty()) {
        
        for (int i = 1; i < m; ++i) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        
        result.push_back(q.front());
        q.pop();
    }


    cout << '<';
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << '>' << '\n';

    return 0;
}
