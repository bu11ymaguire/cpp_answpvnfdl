#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size_a, tmp;
    cin>>size_a;
    unordered_set<int> set_a;
    for(int i=0;i<size_a;i++){
        cin>>tmp;
        set_a.insert(tmp);
    }
    int size_b;
    cin>>size_b;
    unordered_set<int> set_b;
    for(int i=0;i<size_b;i++){
        cin>>tmp;
        set_b.insert(tmp);
    }

    bool is_sub = true;

    if(set_a.size()<=set_b.size()){
        for(int val :set_a ){
            if(set_b.find(val)==set_b.end()){
                is_sub = false;
                break;
            }
        }
    }else{
        for(int val :set_b ){
            if(set_a.find(val)==set_a.end()){
                is_sub = false;
                break;
            }
        }
    }
    if(is_sub){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}
