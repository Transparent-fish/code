#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
string s;
void dfs(int u,vector<int> &p,vector<int> &c){
    if(u==k){
        vector<int> t=c;
        for(int i=0;i<n;i++)if(p[i])t[i]=1;else if(s[i]=='o')t[i]=1;
        int pos=0;
        while(1){
            if(pos+2<n&&t[pos+1]&&t[pos+2]==0){
                pos+=2;
            }else break;
        }
        ans=max(ans,pos+1);
        return;
    }
    for(int i=1;i<n;i++){
        if(s[i]=='o')continue;
        if(!p[i]){
            p[i]=1;dfs(u+1,p,c);p[i]=0;
        }
    }
}
int main(){
    cin>>s>>k;
    n=s.size();
    vector<int> p(n),c(n);
    c[0]=1;
    dfs(0,p,c);
    cout<<ans<<'\n';
}