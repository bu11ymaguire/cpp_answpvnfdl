#include<iostream>
#include<list>
#include<string>
using namespace std;
//insert와 erase 제대로 알기!

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test; cin>>test;
    for(int i = 0; i < test;i++)
    {
        list<char> hello;
        string input; cin>>input;
        auto cursor = hello.begin();
        for(const auto& hi : input)
        {
            if(hi=='<')
            {
                if(cursor!=hello.begin()){
                    cursor--;
                }
            }
            else if(hi=='>'){
                if(cursor!=hello.end()){
                    cursor++;
                }
            }
            else if(hi=='-'){
                if(cursor!=hello.begin()){
                    cursor--;
                    cursor = hello.erase(cursor);
                }
            }
            else
            {
                hello.insert(cursor,hi);
            }
        }
        for(const auto& haha: hello){
            cout<<haha;
        }
        cout<<'\n';
    }
    return 0;
}
