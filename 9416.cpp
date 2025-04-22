#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> s_series(101,0); //오버플로우!!

    for(int i=1;i<=100;i++)
    {
        if(i<=3){s_series[i]=1;}
        else{
            s_series[i] = s_series[i-3]+s_series[i-2];
        }
    }

    int quetsion;
    cin>>quetsion;
    int tmp;
    for(int i=1;i<=quetsion;i++){
        cin>>tmp;
        cout<<s_series[tmp]<<'\n';
    }

    return 0;
}#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> s_series(101,0); //오버플로우!!

    for(int i=1;i<=100;i++)
    {
        if(i<=3){s_series[i]=1;}
        else{
            s_series[i] = s_series[i-3]+s_series[i-2];
        }
    }

    int quetsion;
    cin>>quetsion;
    int tmp;
    for(int i=1;i<=quetsion;i++){
        cin>>tmp;
        cout<<s_series[tmp]<<'\n';
    }

    return 0;
}
