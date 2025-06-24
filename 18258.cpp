#include<iostream>
#include<string>
#include<deque> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> q; 
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            q.push_back(x); 
        } else if (command == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        } else if (command == "size") {
            cout << q.size() << '\n';
        } else if (command == "empty") {
            cout << q.empty() << '\n'; 
        } else if (command == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {

                cout << q.front() << '\n';
            }
        } else if (command == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
