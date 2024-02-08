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

template<typename T>
class segment_tree {//1-based
#define LEFT (idx<<1)
#define RIGHT (idx<<1|1)
#define MID ((start+end)>>1)
	int n;
	vector<T> tree, lazy;
	T merge(const T& left, const T& right) {
		return min(left,right);
	}
	inline void pushdown(int idx, int start, int end) {
		if (lazy[idx] == 0) return;
		//update tree[idx] with lazy[idx]
		tree[idx] += lazy[idx];
		if (start != end) {
			lazy[LEFT] += lazy[idx];
			lazy[RIGHT] += lazy[idx];
		}
		lazy[idx] = 0; //clear lazy
	}
	inline void pushup(int idx) {
		tree[idx] = merge(tree[LEFT], tree[RIGHT]);
	}
	void build(int idx, int start, int end) {
		if (start == end) return;
		build(LEFT, start, MID);
		build(RIGHT, MID + 1, end);
		pushup(idx);
	}
	void build(int idx, int start, int end, const vector<T>& arr) {
		if (start == end) {
			tree[idx] = arr[start];
			return;
		}
		build(LEFT, start, MID, arr);
		build(RIGHT, MID + 1, end, arr);
		pushup(idx);
	}
	T query(int idx, int start, int end, int from, int to) {
		pushdown(idx, start, end);
		if (from <= start && end <= to)
			return tree[idx];
		if (to <= MID)
			return query(LEFT, start, MID, from, to);
		if (MID < from)
			return query(RIGHT, MID + 1, end, from, to);
		return merge(query(LEFT, start, MID, from, to), 
               		  query(RIGHT, MID + 1, end, from, to));
	}

	void update(int idx, int start, int end, int lq, int rq, const T& val) {
		pushdown(idx, start, end);
		if (rq < start || end < lq)
			return;
		if (lq <= start && end <= rq) {
			lazy[idx] += val;//update lazy
			pushdown(idx, start, end);
			return;
		}
		update(LEFT, start, MID, lq, rq, val);
		update(RIGHT, MID + 1, end, lq, rq, val);
		pushup(idx);
	}
public:
	segment_tree(int n) :n(n), tree(n << 2), lazy(n << 2) {}
	segment_tree(const vector<T>& v) {
		n = v.size() - 1;
		tree = vector<T>(n << 2);
		lazy = vector<T>(n << 2);
		build(1, 1, n, v);
	}
	T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update(int l, int r, const T& val) {
		update(1, 1, n, l, r, val);
	}
#undef LEFT
#undef RIGHT
#undef MID
};
void Main(const int &T){
	int n;
	cin>>n;
	vector<ll> v(n+1);
	for(int i=1; i<=n; i++){
		cin>>v[i];
	}
	
	segment_tree<ll> seg(v);
	
	int q;
	cin>>q;
	cin.ignore();
	while(q--){
		string s;
		getline(cin,s);
		stringstream ss;
		ss << s;
		vector<int> query;
		int x;
		while(ss>>x)query.push_back(x);
		query[0]++;
		query[1]++;
		if(query.size()==3){
			if(query[0]>query[1]){
				seg.update(query[0],n,query[2]);
				seg.update(1,query[1],query[2]);
			}else{
				seg.update(query[0],query[1],query[2]);
			}
		}else{
			if(query[0]>query[1]){
				cout<<min(seg.query(query[0], n),seg.query(1, query[1]))<<endl;
			}else{
				cout<<seg.query(query[0], query[1])<<endl;
			}
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
        // cout<<"Case "<< t <<":"<<endl;
        Main(t);
    }
}