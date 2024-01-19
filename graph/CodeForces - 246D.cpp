#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main(){
	file();
	fast();
	int n, m;
	cin >> n >> m;
	vector<int> clr(n);
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++)
		cin >> clr[i];
	while (m--){
		int v, u;
		cin >> u >> v;
		u--; v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	vector<set<int>> a(100005);
	for (int i = 0; i < n; i++)
	for (int j : adj[i])
	if (clr[i] != clr[j])
		a[clr[i]].insert(clr[j]);

	int mx = 0, z = 1e9;
	for (int i : clr)z = min(z, i);
	for (int i = 0; i < 100005; i++)
	if (a[i].size()>mx){
		mx = a[i].size();
		z = i;
	}
	cout << z;
}