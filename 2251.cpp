#include<bits/stdc++.h>
using namespace std;
//BFS의 기초: 현재 상태 → 가능한 모든 다음 상태들 생성 → 유효하고 미방문이면 큐에 추가

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A,B,C; cin >> A >> B >> C;
    vector<vector<bool>> visited(A+1,vector<bool>(B+1,false));
    vector<bool> able(C+1,false);

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        int a = now.first;
        int b = now.second;
        visited[a][b] = true;
        int c = C - (a+b);
        if(a==0)able[c] = true;

        //경우의 수(A,B),(A,C),(B,A),(B,C),(C,A),(C,B)
        /*
        범위 유효성: from -> to에 대해서. 옮기는 물은 from에 있는 양보다 많을 수 없다.
        to의 용량을 초과해서 물을 받을 수 없다. 죽, from에서 to로 옮길 수 있는 물의 양은
        min(from_current,to_total - to_current)
        */
        
        int water_1 = min(a,B-b);
        int a_1 = a - water_1;
        int b_1 = b + water_1;
        if(!visited[a_1][b_1]){q.push({a_1,b_1});visited[a_1][b_1]=true;}

        int water_2 = min(a,C-c);
        int a_2 = a - water_2;
        int b_2 = b;
        if(!visited[a_2][b_2]){q.push({a_2,b_2});visited[a_2][b_2]=true;}

        int water_3 = min(b,A-a);
        int a_3 = a + water_3;
        int b_3 = b - water_3;
        if(!visited[a_3][b_3]){q.push({a_3,b_3});visited[a_3][b_3]=true;}

        int water_4 = min(b,C-c);
        int a_4 = a;
        int b_4 = b - water_4;
        if(!visited[a_4][b_4]){q.push({a_4,b_4});visited[a_4][b_4]=true;}

        int water_5 = min(c,A-a);
        int a_5 = a + water_5;
        int b_5 = b;
        if(!visited[a_5][b_5]){q.push({a_5,b_5});visited[a_5][b_5]=true;}

        int water_6 = min(c,B-b);
        int a_6 = a;
        int b_6 = b + water_6;
        if(!visited[a_6][b_6]){q.push({a_6,b_6});visited[a_6][b_6]=true;}
    }

    for(int i =0; i <=C;i++)
    {
        if(able[i]){
            cout << i <<' ';
        }
    }

    return 0;
}
