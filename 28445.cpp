#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector<string> feather;
    unordered_map<string,int> check_color;

    string c_1;
    string c_2;

    for(int i=1;i<=2;i++){
        cin>>c_1>>c_2;
        if(check_color[c_1]==1){} // unorederd_map의 특징으로 인해 문법상 오류 x
        else{check_color[c_1]=1;feather.push_back(c_1);}

        if(check_color[c_2]==1){} //
        else{check_color[c_2]=1;feather.push_back(c_2);}
    }

    sort(feather.begin(),feather.end());
    for(int i=0;i<feather.size();i++){
        for(int j=0;j<feather.size();j++){
            cout<<feather[i]<<" "<<feather[j]<<'\n';
        }
    }

    return 0;
}
