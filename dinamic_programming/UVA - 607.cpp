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

int n;
int c,l;
vector<vector<pii>> mem;
vector<vector<bool>> vis;
vector<int> a;

int clc(int cnt){
    cnt=l-cnt;
    if(cnt==0)return 0;
    if(cnt<=10)return -c;
    return pow(cnt-10,2);
}
pii solve(int i, int cnt){
    if(cnt>l)return {1e9,1e9};
    if(i==n)return {1,clc(cnt)};

    auto & ref=mem[i][cnt];
    if(vis[i][cnt])return ref;
    vis[i][cnt]=true;

    pii ch1=solve(i+1,cnt+a[i]);
    pii ch2=solve(i+1,a[i]);
    ch2.first++;
    ch2.second+=clc(cnt);

    return ref=min(ch1,ch2);
}
void Main(const int &T){
    int cas=1;
    while(cin>>n){
        if(n==0)break;
        cin >> l >> c;
        a=vector<int>(n);
        cin >> a;
        vis=vector<vector<bool>>(n,vector<bool>(l+1));
        mem=vector<vector<pii>>(n,vector<pii>(l+1));
        auto ans=solve(0,0);
        if(cas>1)cout<<endl;
        cout<<"Case "<<cas++<<":"<<endl;
        cout<<"Minimum number of lectures: "<<ans.first<<endl;
        cout<<"Total dissatisfaction index: "<<ans.second<<endl;
    }
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