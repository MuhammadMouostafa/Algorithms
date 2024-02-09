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
struct sparse_table {
	vector<vector<T>> sparseTable;
	using F = function<T(T, T)>;
	F merge;
	static int LOG2(long long x) { //floor(log2(x))
		return 63 - __builtin_clzll(x);
	}

	sparse_table(ll mxlen,vector<T>& v, F merge) :
		merge(merge) {
		int n = v.size();
		int logN = LOG2(mxlen);
		sparseTable = vector<vector<T>>(logN + 1);
		sparseTable[0] = v;
		for (int k = 1, len = 1; k <= logN; k++, len <<= 1) {
			sparseTable[k].resize(n);
			for (int i = 0; i < n; i++)
				sparseTable[k][i] = merge(sparseTable[k - 1][i],
					sparseTable[k - 1][sparseTable[k - 1][i].to]);
		}
	}
	
	T query_shifting(int i, ll mxlen) {
		T res;
		bool first = true;
		for(int pw=LOG2(mxlen); pw>=0; pw--){
			if(mxlen&(1LL<<pw)){
				if (first)
					res = sparseTable[pw][i],first=false;
				else
					res = merge(res, sparseTable[pw][res.to]);
			}
		}
		return res;
	}
};	

struct segment{
	int mn,to;
	ll sum;
	segment():mn(1e9),sum(0){}
	segment(int mn, ll sum, int to):mn(mn),sum(sum),to(to){}
};
void Main(const int &T){
	int n;
	ll k;
	cin>>n>>k;
	vector<segment> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i].to;
	}

	for(int i=0; i<n; i++){
		cin>>v[i].mn;
		v[i].sum=v[i].mn;
	}

	sparse_table<segment> sp(k,v,[](segment a, segment b){
		return segment(min(a.mn,b.mn),a.sum+b.sum,b.to);
	});


	for(int i=0; i<n; i++){
		segment res=sp.query_shifting(i,k);
		cout<<res.sum<<" "<<res.mn<<endl;
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