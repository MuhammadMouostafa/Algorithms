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

// int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
// int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dx[] = {-1,-1,0, 1, 1,1, 0,-1};
int dy[] = {0, 1, 1, 1, 0,-1, -1,-1};

char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

vector<int> a;
void generate(int x, int len){
    a.push_back(x);
    if(len==9){
        return;
    }
    generate(x*10+7,len+1);
    generate(x*10+4,len+1);
}
void Main(const int &T){
    int pl,pr,vl,vr,k;
    cin>>pl>>pr>>vl>>vr>>k;
    generate(4,1);
    generate(7,1);
    sort(a.begin(),a.end());
    double space=(pr-pl+1)*1.0*(vr-vl+1);
    ll cnt=0;
    for(int i=k-1; i<a.size(); i++){
        int L=a[i-k+1],R=a[i];
        if(pl<=L&&R<=vr){
            int Ll=pl-1;
            if(i-k+1>0){
                Ll=max(Ll,a[i-k]);
            }
            int Lr=min(L,pr);

            int Rr=vr+1;
            if(i+1!=a.size()){
                Rr=min(Rr,a[i+1]);
            }
            int Rl=max(R,vl);

            if(Ll<Lr&&Rl<Rr){
                cnt+=(Lr-Ll)*1LL*(Rr-Rl);
            }

        }
        if(vl<=L&&R<=pr){
            int Ll=vl-1;
            if(i-k+1>0){
                Ll=max(Ll,a[i-k]);
            }
            int Lr=min(L,vr);

            int Rr=pr+1;
            if(i+1!=a.size()){
                Rr=min(Rr,a[i+1]);
            }
            int Rl=max(R,pl);

            if(Ll<Lr&&Rl<Rr){
                if(k==1)cnt--;
                cnt+=(Lr-Ll)*1LL*(Rr-Rl);
            }
        }
    }
    cout<<fixed<<setprecision(9)<<cnt/space<<endl;
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