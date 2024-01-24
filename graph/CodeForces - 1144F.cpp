//#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
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
int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> a;
map < pair<int, int>, int > mp;
bool ok = 1;
void dfs(int nod, int lef){
	a[nod] = lef;
	vis[nod] = 1;
	for (int i : adj[nod])
	if (!vis[i])
		dfs(i, 1 - lef);
	else if (lef == a[i])
		ok = 0;
}
int main()
{
	/***  بسم الله توكلت علي الله  ***/
	file();
	fast();
	cin >> n >> m;
	a = vector<int>(n);
	adj = vector<vector<int>>(n);
	vis = vector<bool>(n, 0);
	//int mx = 0;
	vector<vector<int>> q(m, vector<int>(2));
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		q[i] = { u, v };
		adj[u].push_back(v);
		adj[v].push_back(u);
		//mx = max({ mx, (int)adj[u].size(), (int)adj[v].size() });
	}
	dfs(0, 1);
	if (!ok){
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < m; i++)
		cout << a[q[i][0]];
}
/*

int n;
cin >> n;
string s, t;
cin >> s >> t;
reverse(s.begin(), s.end());
reverse(t.begin(), t.end());
while (n&&s.back() == t.back()){
n--;
cout << s.back();
s.pop_back();
t.pop_back();
}
reverse(s.begin(), s.end());
reverse(t.begin(), t.end());
*/