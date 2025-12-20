//못풀어서 gemini 도움을 받아서 겨우 풀어가지고 예비소집 출석을 인정받았다(...)
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double N; int q;
    cin >> N >> q;
    double ratio = (double)q/100;
    double after = N * (1-ratio);
    double result = N / after;
    
    cout << fixed;
    cout.precision(6);
    cout << (result-1) * 100;
    
    return 0;
}
