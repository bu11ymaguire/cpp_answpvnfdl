#include<iostream>
#include<vector>
using namespace std;

void point_dot(int n, int x,int y, vector<vector<char>> &hello)
{
    if(n==1)
    {
        hello[x][y]='*';
        return;
    }
    int div = n/3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if((i==1)&&(j==1)){continue;}
            point_dot(div,x+div*i,y+div*j,hello);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<char>> hello_world(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            hello_world[i].push_back(' ');
        }
    }
    point_dot(n,0,0,hello_world);
    for(int i=0;i<n;i++)
    {
        for(char character:hello_world[i])
        {
            cout<<character;
        }
        cout<<'\n';
    }

    return 0;
}
