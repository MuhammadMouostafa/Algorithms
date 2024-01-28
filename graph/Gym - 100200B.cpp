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
// #ifndef ONLINE_JUDGE
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
// #endif
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

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> articulation_point;
vector<pair<int, int>> bridge;
stack<pair<int, int>> edges;
vector<vector<pair<int, int>>> BCC; //biconnected components
int timer, cntChild;

void dfs(int node, int par) {
	dfs_num[node] = dfs_low[node] = ++timer;
	for (int child : adj[node]) {
		if (par != child && dfs_num[child] < dfs_num[node])
			edges.push({ node, child });


		if (!dfs_num[child]) {
			if (par == -1)
				cntChild++;

			dfs(child, node);
			if (dfs_low[child] >= dfs_num[node]) {
				articulation_point[node] = 1;
				//get biconnected component
				BCC.push_back(vector<pair<int, int>>());
				pair<int, int> edge;
				do {
					edge = edges.top();
					BCC.back().push_back(edge);
					edges.pop();
				} while (edge.first != node || edge.second != child);
			}
                  //can be (dfs_low[child] == dfs_num[child])
			if (dfs_low[child] > dfs_num[node]) 
				bridge.push_back({ node, child });
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (child != par)
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
	}
}

void articulation_points_and_bridges() {
	timer = 0;
	dfs_num = dfs_low = vector<int>(adj.size());
	articulation_point = vector<bool>(adj.size());
	bridge = vector<pair<int, int>>();
	for (int i = 0; i < adj.size(); i++)
		if (!dfs_num[i]) {
			cntChild = 0;
			dfs(i, -1);
			articulation_point[i] = cntChild > 1;
		}
}

void Main(const int &T){
    int n,m;
    cin>>n>>m;

    adj=vector<vector<int>>(n);
    map<pii,vector<int>> mp;
   for(int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        mp[{min(u,v),max(u,v)}].push_back(i);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    articulation_points_and_bridges();

    vector<int> ans;
    for(pii p:bridge){
        if(p.first>p.second)swap(p.first,p.second);
        if(mp[p].size()==1){
            ans.push_back(mp[p][0]);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main()
{
    file();
    fast();
    int T = 1;
    // cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case "<< t <<": ";
        Main(t);
    }
}