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
struct edge{
	int from, to, w;
	edge(int from, int to, int w) : from(from), to(to), w(w){}
	bool operator < (const edge & e)const{
		return w > e.w;
	}
};
struct unioneFind{
	vector<int> rank, parent;
	int forest;
	unioneFind(int n){
		forest = n;
		rank = parent = vector<int>(n, 1);
		lp(i, n) parent[i] = i;
	}
	int findSet(int x){
		if (parent[x] == x) return x;
		return parent[x] = findSet(parent[x]);
	}
	void link(int x, int y){
		if (rank[x] > rank[y])  swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
	}
	bool unioneSet(int x, int y){
		x = findSet(x); y = findSet(y);
		if (x != y){
			link(x, y); forest--;
		}
		return x != y;
	}
};
vector<edge>  mstKruskal(vector<edge> edgelist, int n){
	unioneFind uf(n);
	vector<edge> edges;
	int mstcost = 0;
	priority_queue<edge> q;
	rep(i, edgelist) q.push(edgelist[i]);
	while (!q.empty()){
		edge e = q.top(); q.pop();
		if (uf.unioneSet(e.from, e.to)){
			mstcost += e.w;
			edges.push_back(e);
		}
	}
	return edges;
}
bool ok = 1;
vector< vector<edge> > adj;
vector<bool> vis;
vector< vector<int> >s;
void dfs(int sr,int cur,ll sum){
	if (s[sr][cur] != sum){
		ok = 0;
		return;
	}
	vis[cur] = 0;
	rep(i, adj[cur])
	if (vis[adj[cur][i].to])
		dfs(sr,adj[cur][i].to, sum + adj[cur][i].w);
}
bool good(int n, vector< vector<int> > a){
	lp(i, n)
		lp(j, n)
	if (i != j&&(a[i][j] != a[j][i]||!a[i][j]) || i == j&&a[i][j])
		return 0;
	return 1;
}
int main(){
	fast();
	int n;
	vector<edge> a;
	cin >> n;
	s=vector< vector<int> >(n, vector<int>(n));
	lp(i, n)
		lp(j, n){
			int w;
			cin >> w;
			s[i][j] = w;
			if (i>j)
			a.push_back({i,j,w});
		}
	if (good(n, s)){
		a = mstKruskal(a, n);
		adj = vector< vector<edge> >(n, vector<edge>());
		rep(i, a){
			int from, to, w;
			from = a[i].from; to = a[i].to; w = a[i].w;
			adj[from].push_back({ from, to, w });
			adj[to].push_back({ to, from, w });
		}
		lp(i, n){
			vis = vector<bool>(n, 1);
			dfs(i, i, 0);
		}
		if (ok)
			cout << "YES";
		else cout << "NO";
	}
	else cout << "NO";
	
	stop();
	return 0;
}