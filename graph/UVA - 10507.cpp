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
    freopen("output.out", "w", stdout);
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

struct DSU {
	map<char,int> rank, parent, size;
	string s;
	// vector<vector<int>> component;
	int forsets;
	DSU(int n, string s):s(s) {
		for(char i:s){
			size[i]=1;
			rank[i]=1;
			parent[i]=i;
		}
		// component = vector<vector<int>>(n + 1);
		forsets = n;
	}
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}
	void link(int par, int node) {
		parent[node] = par;
		size[par] += size[node];
		// for (const int& it : component[node])
		// 	component[par].push_back(it);
		// component[node].clear();
		if (rank[par] == rank[node])
			rank[par]++;
		forsets--;
	}
	bool union_sets(int v, int u) {
		v = find_set(v), u = find_set(u);
		if (v != u) {
			if (rank[v] < rank[u])
				swap(v, u);
			link(v, u);   
		}
		return v != u;
	}
	bool same_set(int v, int u) {
		return find_set(v) == find_set(u);
	}
	int size_set(int v) {
		return size[find_set(v)];
	}
};



void Main(const int &T){
	int n,m;
	while(cin>>n){
		cin>>m;
		set<char> sst;
		map<char,vector<char>> adj;
		string s;
		cin>>s;
		while(m--){
			string uv;
			cin>>uv;
			sst.insert(uv[0]);
			sst.insert(uv[1]);
			adj[uv[0]].push_back(uv[1]);
			adj[uv[1]].push_back(uv[0]);
		}
		string ss;
		for(char i:sst)ss.push_back(i);
		DSU uf(n,ss);
		uf.union_sets(s[0],s[1]);
		uf.union_sets(s[0],s[2]);
		int rem=n-3;
		int years=0;
		set<char> vis;
		vis.insert(s[0]);
		vis.insert(s[1]);
		vis.insert(s[2]);
		while(rem){
			years++;
			int num=0;

			set<int> st;
			for(auto p:adj){
				if(vis.find(p.first)==vis.end()){
					int cnt=0;
					for(char ch:p.second){
						cnt+=vis.find(ch)!=vis.end();
					}
					if(cnt>=3){
						st.insert(p.first);
						num++;
						uf.union_sets(p.first,s[0]);
					}
				}
			}
			for(char X:st){
				vis.insert(X);
			}

			rem-=num;
			if(!num){
				break;
			}
		}
		if(rem){
			cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
		}else{
			cout<<"WAKE UP IN, "<< years <<", YEARS"<<endl;
		}
	}



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