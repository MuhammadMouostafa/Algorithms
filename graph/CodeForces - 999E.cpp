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
vector<bool>  instak;
vector< vector<int> > adj, adj2, scc;
vector<int> dfn, lown, comp;
int tim;
stack<int> k;
void tarjan(int nod){
	instak[nod] = 1;
	k.push(nod);
	dfn[nod] = lown[nod] = tim++;
	for (int i = 0; i < adj[nod].size(); i++){
		int ch = adj[nod][i];
		if (dfn[ch] == -1){
			tarjan(ch);
			lown[nod] = min(lown[nod], lown[ch]);
		}
		else if (instak[ch])
			lown[nod] = min(lown[nod], dfn[ch]);
	}
	if (dfn[nod] == lown[nod]){
		scc.push_back(vector<int>());
		int x = -1;
		while (x != nod){
			x = k.top(); k.pop(); instak[x] = 0;
			scc.back().push_back(x);
			comp[x] = scc.size() - 1;
		}
	}
}
int main(){
	/* بسم الله توكلت علي الله */
	file();
	fast();
	int n,m,s;
	cin >> n >> m >> s;
	s--;
	tim = 0;
	dfn = lown = comp = vector<int>(n, -1);
	adj = vector < vector<int>>(n, vector<int>());
	instak = vector<bool>(n, 0);
	while (m--){
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
	if (dfn[i] == -1)
		tarjan(i);
	adj2 = vector < vector<int>>(scc.size(), vector<int>());
	for (int i = 0; i < n; i++)
	for (int j = 0; j < adj[i].size(); j++)
	if (comp[i] != comp[adj[i][j]])
		adj2[comp[adj[i][j]]].push_back(comp[i]);
	int sum = 0;
	for (int i = 0; i<adj2.size(); i++)
	if (!adj2[i].size()&&comp[s]!=i)
		sum++;
	cout << sum << endl;

}