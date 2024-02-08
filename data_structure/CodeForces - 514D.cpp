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
	static int LOG2(int x) { //floor(log2(x))
		return 31 - __builtin_clz(x);
	}
	sparse_table(vector<T>& v, F merge) :
		merge(merge) {
		int n = v.size();
		int logN = LOG2(n);
		sparseTable = vector<vector<T>>(logN + 1);
		sparseTable[0] = v;
		for (int k = 1, len = 1; k <= logN; k++, len <<= 1) {
			sparseTable[k].resize(n);
			for (int i = 0; i + len < n; i++)
				sparseTable[k][i] = merge(sparseTable[k - 1][i],
					sparseTable[k - 1][i + len]);
		}
	}
	T query(int l, int r) {
		int k = LOG2(r - l + 1); // max k ==> 2^k <= length of range
		//check first 2^k from left and last 2^k from right //overlap
		return merge(sparseTable[k][l], sparseTable[k][r - (1 << k) + 1]);
	}
	T query_shifting(int l, int r) {
		T res;
		bool first = true;
		for (int i = (int)sparseTable.size() - 1; i >= 0; i--)
			if (l + (1 << i) - 1 <= r) {
				if (first)
					res = sparseTable[i][l];
				else
					res = merge(res, sparseTable[i][l]);
				first = false;
				l += (1 << i);
			}
		return res;
	}
};	



void Main(const int &T){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> v(m,vector<int>(n+1));
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			cin>>v[j][i];
		}
	}
	vector<sparse_table<int>> sp;
	for(auto a:v){
		sp.push_back(sparse_table<int>(a,[](int x, int y){
			return max(x,y);
		}));
	}

	pair<int,vector<int>> mx={0,vector<int>(m)};
	for(int i=1; i<=n; i++){
		int lo=i,hi=n;
		pair<int,vector<int>> ans={-1,vector<int>(m)};
		while(lo<=hi){
			int mid=(lo+hi)/2;
			vector<int> res(m);
			ll sum=0;
			for(int j=0; j<m; j++){
				res[j]=sp[j].query(i,mid);
				sum+=res[j];
			}
			if(sum<=k){
				ans={mid-i+1,res};
				lo=mid+1;
			}else{
				hi=mid-1;
			}
		}

		if(ans.first>mx.first){
			mx=ans;
		}
	}
	cout<<mx.second<<endl;
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