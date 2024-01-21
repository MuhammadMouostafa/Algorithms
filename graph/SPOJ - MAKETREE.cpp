//#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-6
#define OO 1e9
#define PI acos(-1.0)
#define ll long long
#define endl "\n"
#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define sch(x)  scanf("%c",&x)
#define scs(x)  scanf("%s",x)
#define prl(x) printf("%lld",x)
#define pr(x)  printf("%d",x)
#define prs(x) printf("%s",x)
#define prline printf("\n");
void file(){
#ifndef ONLINE_JUDGE
	freopen("a_input.txt", "r", stdin);
	freopen("a_output.txt", "w", stdout);
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
ll setbit(ll num, int idx, int val = 1){ return (val) ? (num | (1 << idx)) : (num&~(1 << idx)); }
ll getbit(ll num, int idx){ return ((num >> idx) & 1) == 1; }
int contbit(int num){ int ret = 0; while (num){ if (num % 2)ret++; num /= 2; }return ret; }
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
vector<vector<int>> adj;
vector<int> vis;
queue<int> tree;
void topoligicalSoert(int node){
	vis[node] = 1;
	for (int i : adj[node])
	if (!vis[i])
		topoligicalSoert(i);
	tree.push(node);
}
int main()
{
	file();
	fast();
	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	vis = vector<int>(n + 1, 0);
	for (int u = 1; u <= m; u++){
		int v, w;
		cin >> w;
		while (w--){
			cin >> v;
			adj[v].push_back(u);
		}
	}
	for (int i = 1; i <= n; i++)
	if (!vis[i])
		topoligicalSoert(i);
	int par = 0;
	while (tree.size()){
		int ch = tree.front();
		tree.pop();
		vis[ch] = par;
		par = ch;
	}
	for (int i = 1; i <= n; i++)
		cout << vis[i] << endl;

}