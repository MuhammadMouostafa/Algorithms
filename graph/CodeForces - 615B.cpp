#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  rep(i,v)       for(int i=0; i<(int)v.size(); i++)
#define cini(n)         scanf("%d",&n)
#define cinl(n)         scanf("%lld",&n)
#define cind(n)         scanf("%Lf",&n)
#define cinf(n)         scanf("%f",&n)   
#define cinc(n)         scanf("%c",&n)
#define cins(n)         scanf("%s",&n)
#define cinsl(n)        cin.ignore(), scanf("%[^\n]%*c",n)
#define couti(n)         printf("%d",n)
#define coutl(n)         printf("%lld",n)
#define coutd(n)         printf("%Lf",n)
#define coutdd(n)         printf("%.9l f",n)
#define coutf(n)         printf("%f",n)   
#define coutc(n)         printf("%c",n)
#define coutarc(n)         printf("%s",n)
#define couts(n)         printf("%s",n.c_str())
#define coutln()         printf("\n")   
#define coutsp(n)         printf(" ")

typedef  long long ll;
using namespace std;
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector< vector<int> > adj,adj1;
vector<ll> vis;
int dfs(int node){
	if (vis[node] != -1)
		return vis[node];
	int mx = 0;
	rep(i, adj[node]){
		int ch = adj[node][i];
		mx = max(mx, dfs(ch));
	}
	return vis[node]=mx + 1;
}
int main(){
	fast();
	int n, m;
	cin >> n >> m;
	adj1=adj = vector< vector<int> >(n, vector<int>());
	vis = vector<ll>(n, -1);
	lp(i, m){
		int from, to;
		cin >> from >> to;
		from--; to--;
		adj1[from].push_back(to);
		adj1[to].push_back(from);
		if (from<to)
			adj[to].push_back(from);
		else adj[from].push_back(to);
	}
	ll mx = 0;
	lp(i, n){
		if (vis[i] == -1)
			dfs(i);
		mx = max(mx, vis[i] * adj1[i].size());
	}
	cout << mx << endl;
	stop();
	return 0;
}