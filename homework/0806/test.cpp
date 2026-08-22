#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,b[114514<<2],c[114514<<2];
struct node{
	int x,y;
	bool operator<(node b)const{
		return this->y < b.y;
	}
}a[114514<<2],pp[114514<<2];
priority_queue<node>qq;
bool cmp(node x,node y){
	return x.x>y.x;
}
bool check(int k){
	if((long long)(n-p-q)*k>=m)return 1;//不需要挑剔和贫穷的人就可以取完
	while(qq.size())qq.pop();//多测清空，因为函数最后直接加上 size 了，下一次调用不清空会出错
	int top=1;
	for(int i=1;i<=p;i++) {
		while(top<=m&&a[top].x>=b[i])qq.push(a[top++]);
		for(int j=1;j<=k&&qq.size();j++)qq.pop(); 
	}//枚举挑剔的人
	int cnt=0;
	while(qq.size()){
		pp[++cnt]=qq.top();
		qq.pop();
	} 
	for(int i=top;i<=m;i++)pp[++cnt]=a[i];
	sort(pp+1,pp+cnt+1);//存入数组，按价格升序排序
	top=1;
	for(int i=1;i<=q;i++) {
		while(top<=cnt&&pp[top].y<=c[i])qq.push(pp[top++]);
		for(int j=1;j<=k&&qq.size();j++)qq.pop();
	}//枚举贫穷的人
	int res=qq.size()+cnt-top+1;
	return(res<=(n-p-q)*k);//判断剩下的人能不能取完
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>p>>q;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=p;i++)cin>>b[i];
	for(int i=1;i<=q;i++)cin>>c[i];
	sort(b+1,b+p+1);
	reverse(b+1,b+p+1);
	sort(c+1,c+q+1);
	sort(a+1,a+m+1,cmp);//全部排序
	int l=1,r=m,ans=-1;//设为 -1 可以直接判无解
	while(l<=r){//二分板子
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
}
