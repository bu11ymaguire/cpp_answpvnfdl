#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int node,root;
    cin>>node>>root;
    vector<int> reference(node+1,0);
    vector<vector<int>> adjlist(node+1);
    for(int i=0;i<root;i++){
        int from,to;
        cin>>from>>to;
        adjlist[from].push_back(to);
        reference[to]++;
    }
    queue<int> topological;
    for(int i=1;i<=node;i++)
    {
        if(reference[i]==0){
            topological.push(i);
        }
    }
    vector<int> order;
    while(!topological.empty())
    {
        int current_node = topological.front();
        topological.pop();
        order.push_back(current_node);

        for(int i=0;i<adjlist[current_node].size();i++)
        {
            reference[adjlist[current_node][i]]--;
            if(reference[adjlist[current_node][i]]==0)
            {
                topological.push(adjlist[current_node][i]);
            }
        }
    }

    for(int i=0;i<order.size();i++)
    {
        cout<<order[i]<<' ';
    }
    return 0;
}
