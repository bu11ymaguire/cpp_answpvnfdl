#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tre;
    string tmp;
    cin>>tre;

    int baknbock;
    for(int i=0;i<tre;i++){
        cin>>baknbock;
        cin>>tmp;
        for(int j=0;j<tmp.size();j++)
        {
            for(int k=0;k<baknbock;k++){
                cout<<tmp[j];
            }
        }
        cout<<'\n';
    }
    return 0;
}
