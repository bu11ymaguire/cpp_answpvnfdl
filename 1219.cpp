#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
//벨만 포드로 양의 사이클에 포함되는 노드들 탐색 -> BFS로 해당 사이클에 from -> to 가 포함되는지 확인!

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int city,from,to,by;
    cin>>city>>from>>to>>by;

    vector<vector<pair<int,int>>> city_info(city);
    vector<long long> pay(city,LLONG_MIN);
    vector<long long> reward(city); 

    for(int i = 0 ; i < by ; i++)
    {
        int tmp_from,tmp_to,tmp_pay;
        cin>>tmp_from>>tmp_to>>tmp_pay;
        city_info[tmp_from].push_back({tmp_to,tmp_pay});
    }

    for(int i = 0 ; i < city; i++)
    {
        cin>>reward[i];
    }

    pay[from] = reward[from]; //pay[from] = 0(원래 시작점) + reward[from]

    for(int i = 0; i <city-1 ;i++)
    {
        for(int j = 0 ; j < city ; j++)
        {
            if(pay[j]==LLONG_MIN) continue;

            for(const auto& hello: city_info[j])
            {
                int tmp_to = hello.first;
                int tmp_pay = hello.second;

                pay[tmp_to] = max(pay[tmp_to],pay[j]-tmp_pay+reward[tmp_to]);                
            }
        }
    }

    if(pay[to]==LLONG_MIN)cout<<"gg\n"; //도달X

    else
    {
        vector<bool> has_positive(city,false);

        for(int j = 0; j < city;j++)
        {
            if(pay[j]==LLONG_MIN)continue;
            for(const auto& hello:city_info[j])
            {
                int tmp_to = hello.first;
                int tmp_pay = hello.second;
                long long new_val = pay[j] - tmp_pay + reward[tmp_to];

                if(new_val>pay[tmp_to])
                {
                    pay[tmp_to] = new_val;
                    has_positive[tmp_to] = true;
                }
            }
        }

        queue<int> graph_search;
        vector<bool> has_visited(city,false);

        for(int i = 0; i<city;i++)
        {
            if(has_positive[i]&&!has_visited[i]){
                graph_search.push(i);
                has_positive[i] = true;
            }
        }

        while(!graph_search.empty())
        {
            int now_node = graph_search.front();
            graph_search.pop();

            for(const auto& hello:city_info[now_node])
            {
                int temp_node = hello.first;
                if(!has_visited[temp_node])
                {
                    has_positive[temp_node] = true;
                    has_visited[temp_node] = true;
                    graph_search.push(temp_node);
                }
            }
        }

        if(has_positive[to])cout<<"Gee\n";
        else cout<<pay[to]<<'\n';
        
    }
    return 0;
}
