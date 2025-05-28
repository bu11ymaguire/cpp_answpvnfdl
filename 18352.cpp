#include <iostream>
#include <vector>
#include <queue>
#include <climits> 

using namespace std;

const int INF = INT_MAX; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int city, rode, target_weight, start_node; 

    cin >> city >> rode >> target_weight >> start_node;

    vector<vector<int>> adj(city + 1); 

    for (int i = 0; i < rode; ++i) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
    }
    vector<int> dist(city + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node}); 

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop(); 

        if (current_dist > dist[current_node]) {
            continue;
        }

        for (int next_node : adj[current_node]) {
            int next_dist = current_dist + 1; 

            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node}); 
            }
        }
    }

    vector<int> result_cities;
    for (int i = 1; i <= city; ++i) {
        if (dist[i] == target_weight) {
            result_cities.push_back(i);
        }
    }

    if (result_cities.empty()) 
    {
        cout << -1;
    } else {
        for(int i=0;i<result_cities.size();i++)
        {
            cout<<result_cities[i]<<' ';
        }
    }

    return 0;
}
