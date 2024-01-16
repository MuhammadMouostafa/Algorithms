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

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

struct box
{
    int pos,candies;
    char clr;
    box(int pos, int candies, char clr):
    pos(pos),candies(candies),clr(clr){}
    box():box(0,0,'0'){}

    bool operator <(const box& other){
        return candies<other.candies;
    }
};

int n;
vector<box  > a;
int mem[51][51][2001];
int solve(int i, int prev, int rem){
    if(rem<=0)return 0;
    if(i==n+1)return 1e9;

    int &ref=mem[i][prev][rem];
    if(~ref)return ref;

    ref=solve(i+1,prev,rem);

    if(a[i].candies>a[prev].candies&&a[i].clr!=a[prev].clr){
        ref=min(ref,abs(a[i].pos-a[prev].pos)+solve(i+1,i,rem-a[i].candies));
    }

    return ref;
}
void Main(const int &T){
    int s,k;
    cin>>n>>s>>k;

    a=vector<box>(n+1);
    a[0].candies=0;
    a[0].pos=s;

    for(int i=1; i<=n; i++){
        cin>>a[i].candies;
        a[i].pos=i;   
    }
    for(int i=1; i<=n; i++){
        cin>>a[i].clr;
    }
    sort(a.begin(),a.end());
    memset(mem,-1,sizeof mem);
    int ans=solve(1,0,k);
    cout<<(ans>=1e9?-1:ans)<<endl;
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