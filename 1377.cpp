#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,tmp;
    cin>>N;
    vector<pair<int,int>> hello(N);
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        hello[i].first = tmp;
        hello[i].second = i;
    }
    sort(hello.begin(),hello.end());

    int max_diff = 0;

    for(int i=0;i<N;i++)
    {
        max_diff = max(max_diff,hello[i].second-i); 
    /*배열이 오름차순으로 배열되기 위한 큰 수를 오른쪽으로 밀어내기의 최소 횟수는 (기존 인덱스 - 정렬된 인덱스)의 최댓값과 같다. 특정숫자가 왼쪽으로 밀려낳는 횟수는 큰 수를 오른쪽으로 밀어내기 1회당 한번이므로 
    기존 인덱스 - 정렬된 인덱스)의 최댓값은 swap이 더 이상 일어나지 않을떄까지 필요한 밀어내기의 횟수를 가리킨다.*/
    }
    cout<<max_diff+1; //이후 더 이상 swap이 일어나지 않음을 관측하기 위한 추가횟수 1을 더해준다.
    return 0;
}
