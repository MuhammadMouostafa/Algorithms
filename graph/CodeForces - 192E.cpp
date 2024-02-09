    #define _CRT_SECURE_NO_WARNINGS
#ifdef __GNUC__
# define ffs(x) __builtin_ffs(x)
#elif __INTEL_COMPILER
# define ffs(x) _bit_scan_forward(x)
#endif
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;



using ll = long long;
#define all(v) v.begin(),v.end()
#define EPS 1e-10
#define INF 1e18
#define PI acos(-1.0)
#define sz(s)    (int)(s.size())
#define endl "\n"
void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
#endif
}
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

template<class val>
istream& operator>>(istream& is, vector<val>& vec) {
    for (int i = 0; i < vec.size(); i++)
        is >> vec[i];
    return is;
}
template<class val>
ostream& operator<<(ostream& os, vector<val>& vec) {
    for (int i = 0; i < sz(vec); i++) {
        os << vec[i];
        if (i + 1 < sz(vec))
            os << ' ';
    }
    return os;
}
template<class f, class s>
istream& operator>>(istream& is, pair<f, s>& p) {
    is >> p.first >> p.second;
    return is;
}
template<class f, class s>
ostream& operator<<(ostream& os, pair<f, s>& p) {
    os << "{" << p.first << ',' << p.second << "}";
    return os;
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
// int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dx[] = {-1,-1,0, 1, 1,1, 0,-1};
int dy[] = {0, 1, 1, 1, 0,-1, -1,-1};

char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

class LCA {
    int n, logN, root = 1;
    vector<int> depth;
    vector<vector<int>> adj, lca;
    void dfs(int node, int parent) {
        lca[node][0] = parent;
        depth[node] = (~parent ? depth[parent] + 1 : 0);
        for (int k = 1; k <= logN; k++) {
            int up_parent = lca[node][k - 1];
            if (~up_parent)
lca[node][k] = lca[up_parent][k - 1];
        }
        for (int child : adj[node])
            if (child != parent) 
dfs(child, node);
    }
public:
    LCA(const vector<vector<int>> &_adj, int root = 1) : root(root), adj(_adj) {
        adj = _adj;
        n = adj.size() - 1;
        logN = log2(n);
        lca = vector<vector<int>>(n + 1, vector<int>(logN + 1, -1));
        depth = vector<int>(n + 1);
        dfs(root, -1);
    }
    int get_LCA(int x, int y) {
        if (depth[x] < depth[y])
            swap(x, y);
        for (int k = logN; k >= 0; k--)
            if (depth[x] - (1 << k) >= depth[y])
                x = lca[x][k];
        if (x == y)
            return x;
        for (int k = logN; k >= 0; k--) {
            if (lca[x][k] != lca[y][k]) {
                x = lca[x][k], y = lca[y][k];
            }
        }
        return lca[x][0];
    }
    int get_distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[get_LCA(u, v)];
    }
    int shifting(int node, int dist) {
        for (int i = logN; i >= 0 && ~node; i--)
            if (dist & (1 << i))
                node = lca[node][i];
        return node;
    }
};

vector<int> cnt;
vector<vector<int>> adj;
map<pii,int> idx;
vector<int> ans;
void dfs(int node=1, int par=-1){
	for(int ch:adj[node]){
		if(ch!=par){
			dfs(ch,node);
			ans[idx[{node,ch}]]=cnt[ch];
			cnt[node]+=cnt[ch];
		}
	}
}
void Main(const int &T){
	int n;
	cin>>n;
	adj=vector<vector<int>>(n+1);
	for(int i=0; i+1<n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		idx[{u,v}]=idx[{v,u}]=i;
	}
	LCA g(adj);
	cnt=vector<int>(n+1);
	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		int lca=g.get_LCA(u,v);
		cnt[u]++;
		cnt[v]++;
		cnt[lca]-=2;
	}
	ans=vector<int>(n-1);
	dfs();
	cout<<ans<<endl;
}
int main()
{
    file();
    fast();
    int T = 1;
    // cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case "<< t <<":";
        Main(t);
    }
}