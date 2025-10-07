#include<bits/stdc++.h>
using namespace std;

pair<long long, long long> seeyachump(long long a, long long b)
{
    if(a==0&&b==0){return {0,0};}
    if(a==0){return {0,1};}
    if(b==0){return {1,0};}

    long long divide = gcd(abs(a),abs(b));

    long long A = a/divide;
    long long B = b/divide;

    if(A*B>0)
    {
        return {abs(A),abs(B)};
    }
    else{
        return {abs(A),abs(B)*(-1)};
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<pair<long long,long long>> plus;
    set<pair<long long,long long>> minus;
    map<pair<long long,long long>,long long> count;
    bool zero = false;
    int N; cin >> N;
    while(N--)
    {
        long long one, two; cin >> one >> two;
        auto hi = seeyachump(one,two);
        count[hi]++;
        if(hi.first==0||hi.second==0)
        {
            if(hi.first==0&&hi.second==0)zero = true;
            else
            {
                plus.insert(hi);
            }
            
        }

        if(hi.second<0)
        {
            minus.insert(hi);
        }

        else if(hi.second>0)
        {
            plus.insert(hi);
        }
    }

    long long result = 0;
    bool part_zero = false;
    for(const auto& pl: plus)
    {
        if(pl.first==0||pl.second==0){part_zero=true; continue;}
        if(minus.find({pl.second,pl.first*-1})!=minus.end())
        {
            result += count[pl] * count[{pl.second,pl.first*-1}];
        }
    }
 
    if(part_zero)
    {
        result += count[{1,0}] * count[{0,1}];
    }

    if(zero){
        result += count[{0,0}] * (count[{0,0}]-1) /2;
        result += count[{0,0}] * (N-count[{0,0}]);
    }
    cout << result;
    return 0;
}
