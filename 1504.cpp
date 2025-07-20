#include<iostream>
#include<vector>
#include<queue>
#include<climits> 

using namespace std;

int get_distance(const vector<vector<pair<int, int>>>& weight, int from, int to) {
    vector<int> distance(weight.size(), INT_MAX); 
    distance[from] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> now_queue;
    now_queue.push({0, from});

    while (!now_queue.empty()) {
        int now_weight = now_queue.top().first;
        int now_node = now_queue.top().second;
        now_queue.pop();

        if (distance[now_node] < now_weight) {
            continue;
        }

        for (int i = 0; i < weight[now_node].size(); i++) {
            int next_node = weight[now_node][i].first;
            int next_weight = weight[now_node][i].second;
            int new_weight = now_weight + next_weight;

            if (new_weight < distance[next_node]) {
                distance[next_node] = new_weight;
                now_queue.push({new_weight, next_node});
            }
        }
    }
    return distance[to];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int edge, way; 
    cin >> edge >> way;

    vector<vector<pair<int, int>>> weight(edge + 1);

    for (int i = 0; i < way; i++) {
        int from, to, W;
        cin >> from >> to >> W;
        weight[from].push_back({to, W});
        weight[to].push_back({from, W});
    }

    int essential_1, essential_2;
    cin >> essential_1 >> essential_2;
    
    
    long long distance_1 = (long long)get_distance(weight, 1, essential_1) + get_distance(weight, essential_1, essential_2) + get_distance(weight, essential_2, edge);
    long long distance_2 = (long long)get_distance(weight, 1, essential_2) + get_distance(weight, essential_2, essential_1) + get_distance(weight, essential_1, edge);
    
    long long result = min(distance_1, distance_2);
    
    
    const int INF = 200000000; 
    if (result >= INF) {
        cout << -1 << "\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}
