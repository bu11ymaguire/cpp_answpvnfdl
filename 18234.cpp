#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare_potential(const pair<int,int>&a, const pair<int,int>&b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, time; 
    cin >> N >> time;
    vector<pair<int,int>> carrot_info(N);

    for(int i = 0; i < N; i++)
    {
        int carrot, potential;
        cin >> carrot >> potential;
        carrot_info[i] = {carrot, potential};
    }

    sort(carrot_info.begin(), carrot_info.end(), compare_potential);

    long long result = 0;

    for(int i = 0; i < N; i++) //순회는 N 만큼 순회. time으로 순회하는 경우, time > N 일때 outOfBounds 발생 
    {
        int days_grown = time - N + i; //time > N일때는 먹지 않는 날이 (time-N+i)만큼 발생 
        result += (long long)carrot_info[i].first + (long long)carrot_info[i].second * days_grown;
    }
    cout << result;
    return 0;
}
