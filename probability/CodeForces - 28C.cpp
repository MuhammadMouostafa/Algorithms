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
#define EPS 1e-6
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

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

long long ncr[51][51];
void calculate_ncr() {
     ncr[0][0] = 1;
    for (int n = 1; n < 51; n++) {
        ncr[n][0] = 1;
        for (int r = 1; r < 51; r++) {
            ncr[n][r] = ncr[n-1][r-1] + ncr[n-1][r];
        }
    }
}

double dp[51][51][51];
double p=1;
int n,m;
vector<int> a;
double solve(int i, int rem, int mx){
    if(i==m){
        return rem?0:mx*p;
    }
    double &ref=dp[i][rem][mx];
    if(ref==ref)return ref;
    ref=0;
    for(int j=0; j<=rem; j++){
        ref+=ncr[rem][j]*solve(i+1,rem-j,max(mx,(j+a[i]-1)/a[i]));
    }
    return ref;
}
void Main(const int &T){
    calculate_ncr();
    cin>>n>>m;
    a=vector<int>(m);
    cin>>a;
    for(int i=1; i<=n; i++){
        p/=m;
    }

    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<solve(0,n,0)<<endl;
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