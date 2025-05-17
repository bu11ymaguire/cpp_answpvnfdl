#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, m;
    cin >> N >> m;

    vector<vector<int>> hello(N + 1, vector<int>(N + 1));
    vector<int> reference(N + 1, 0);

    for(int i = 0; i < m; i++) {
        int tri;
        cin >> tri;
        vector<int> order(tri);
        for(int j = 0; j < tri; j++) {
            cin >> order[j];
        }

        for(int j = 0; j < tri - 1; j++) {
            if(hello[order[j]][order[j+1]] == 0) {
                hello[order[j]][order[j+1]] = 1;
                reference[order[j+1]]++;
            }
        }
    }

    queue<int> truing_to_do;
    for(int i = 1; i <= N; i++) {
        if(reference[i] == 0) {
            truing_to_do.push(i);
        }
    }

    vector<int> toopological;
    while(!truing_to_do.empty()) {
        int current = truing_to_do.front();
        truing_to_do.pop();
        toopological.push_back(current);

        for(int i = 1; i <= N; i++) {
            if(hello[current][i] == 1) {
                reference[i]--;
                hello[current][i] = 0; 
                if(reference[i] == 0) {
                    truing_to_do.push(i);
                }
            }
        }
    }

    if(toopological.size() == N) {
        for(int i = 0; i < toopological.size(); i++) {
            cout << toopological[i] << '\n';
        }
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
