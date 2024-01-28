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
vector< vector<int> > adj1,adj2,adj3,scc;
stack<int> k;
vector<bool> vis;
vector<int> comp;
int n, m, t;
void dfs1(int node){
	vis[node] = 1;
	rep(i, adj1[node]){
		int ch = adj1[node][i];
		if (!vis[ch])
			dfs1(ch);
	}
	k.push(node);
}
void dfs2(int node){
	vis[node] = 1;
	rep(i, adj3[node]){
		int ch = adj3[node][i];
		if (!vis[ch])
			dfs2(ch);
	}
	comp[node] = (int)scc.size() - 1;
	scc.back().push_back(node);
}
void kosaraju(){
	lp(i, n)
	if (!vis[i])
		dfs1(i);
	comp = vector<int>(n,-1);
	vis = vector<bool>(n, 0);
	while (k.size()){
		int a = k.top();
		if (!vis[a]){
			scc.push_back(vector<int>());
			dfs2(a);
		}
		k.pop();
	}
}
int main(){
	fast();
		cin >> n >> m;
		adj3=adj1 = vector < vector<int>>(n, vector<int>());
		vis = vector<bool>(n, 0);
		while (m--){
			int from, to;
			cin >> from >> to;
			from--; to--;
			adj1[from].push_back(to);
			adj3[to].push_back(from);
		}
		 kosaraju();
		 adj2 = vector < vector<int>>(scc.size(), vector<int>());
		 lp(i, n)
			 rep(j, adj3[i])
		 if (comp[i] != comp[adj3[i][j]])
			 adj2[comp[adj3[i][j]]].push_back(comp[i]);
		/* rep(i, scc){
			 rep(j, scc[i])
				 cout << scc[i][j]+1<<" ";
			 cout << endl;
		 }*/
		 vector<int> a;
		 rep(i, scc)
		 if (!adj2[i].size()){
			 rep(j, scc[i])
				 a.push_back(scc[i][j]);
		 }
		 sort(a.begin(), a.end());
		 cout << a.size() << endl;
		 rep(i, a)
			 cout << a[i]+1 << " ";
	stop();
	return 0;
}