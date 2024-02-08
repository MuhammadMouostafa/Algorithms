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

const int MAXN = 1e5+5; // maximum array size
int n; // array size
int a[MAXN]; // input array
long long segTree[4*MAXN]; // segment tree

void merge_node(long long &node, long long &ch1, long long &ch2){
	node = ch1 * ch2; // merge results
}
void build(int node, int start, int end) {
    if (start == end) { // leaf node
        segTree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid); // build left subtree
        build(2*node+1, mid+1, end); // build right subtree
        merge_node(segTree[node],segTree[2*node],segTree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) { // leaf node
        a[idx] = val;
        segTree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) { // update left subtree
            update(2*node, start, mid, idx, val);
        } else { // update right subtree
            update(2*node+1, mid+1, end, idx, val);
        }
        merge_node(segTree[node],segTree[2*node],segTree[2*node+1]);
    }
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) { // no overlap
        return 1;
    } else if (l <= start && end <= r) { // complete overlap
        return segTree[node];
    } else { // partial overlap
        int mid = (start + end) / 2;
        long long leftSum = query(2*node, start, mid, l, r); // query left subtree
        long long rightSum = query(2*node+1, mid+1, end, l, r); // query right subtree
        long long ans;
		merge_node(ans, leftSum , rightSum);;
		return ans;
    }
}



void Main(const int &T){
	int q;
	while(cin>>n>>q){
		for(int i=1; i<=n; i++){
			int x;
			cin>>x;
			a[i]=0;
			if(x>0)a[i]=1;
			else if(x<0)a[i]=-1;
		}
		build(1, 1, n);
		
		while(q--){
			char c;
			cin>>c;
			if(c=='C'){
				int i,v;
				cin>>i>>v;
				if(v>0)v=1;
				else if(v<0)v=-1;
				update(1, 1, n, i, v);
			}else{
				int l,r;
				cin>>l>>r;
				int ans=query(1, 1, n, l, r);
				cout<<(ans==0?"0":(ans>0?"+":"-"));
			}
		}
		cout<<endl;
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