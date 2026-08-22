#include <bits/stdc++.h>
using namespace std;
int n;
set<string>se;

int main(){
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        se.insert(s);
    }
    cout << se.size() << '\n';
    return 0;
}

// @pid 214 @tid 6a7afe00f80e134e7823401b @lang cc.cc14o2
