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

struct Ants{
	int mn,g,cnt,mults;
	Ants():mn(MOD),g(MOD),cnt(0),mults(0){}
	Ants(int mn, int g, int cnt, int mults):mn(mn),g(g),cnt(cnt),mults(mults){}
};

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


int solve(string s){
	int n=s.size();
	vector<vector<bool>> dp(n,vector<bool>(n));
	for(int i=0; i<n; i++){
		dp[i][i]=1;
	}
	int cnt=n;
	for(int len=2; len<=n; len++){
		for(int l=0,r=len-1; r<n; l++,r++){
			if(s[l]==s[r]&&(len==2||dp[l+1][r-1])){
				dp[l][r]=1;
				cnt++;
			}
		}
	}
	return cnt;
}
void Main(const int &T){
	int n,q;
	cin>>n>>q;
	map<string,int> mp;
	vector<string> s(n);
	vector<pii> a(n);
	for(int i=0; i<n; i++){
		cin>>s[i];
		mp[s[i]]=i;
		a[i]={solve(s[i]),i+1};
	}

	
	sparse_table<pii> sp(a,[](pii left, pii right){
		if(left.first==right.first){
			return (left.second<right.second)?left:right;
		}	
		return (left.first>right.first)?left:right;
	});



	while(q--){
		string L,R;
		cin>>L>>R;
		int l=mp[L],r=mp[R];
		if(l>r)swap(l,r);
		cout<<sp.query(l,r).second<<endl;
	}
	
}
int main()
{
    file();
    fast();
    int T = 1;
    cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case "<< t <<":";
        Main(t);
    }
}