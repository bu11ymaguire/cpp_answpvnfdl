#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int nine[9];
    vector<int> real; 
    int total;
    int tmp;
    for(int i=0;i<9;i++)
    {
        cin>>tmp;
        nine[i]=tmp;
        total+=tmp;
    }

    if(total>100)
    {
        bool check = false;
        int term = total -100;
        for(int i=0;i<9;i++)
        {
            for(int j=i+1;j<9;j++)
            {
                if(nine[i]+nine[j]==term)
                {
                    nine[i]=0;
                    nine[j]=0;
                    check = true;
                    break;
                }
            }
            if(check){break;}
        }
        if(check){
            for(int i=0;i<9;i++){
                if(nine[i]!=0){real.push_back(nine[i]);}
            }
            sort(real.begin(),real.end());
            for(int i=0;i<real.size();i++){
                cout<<real[i]<<'\n';
            }
        }
    }
    else
    {

    }

    return 0;
}


