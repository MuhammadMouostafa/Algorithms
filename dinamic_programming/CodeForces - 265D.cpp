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

vector<int> getPrimeFactors(int n) {
    vector<int> factors;

    int count = 0;
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0) {
        factors.push_back(2);
    }

    for (int i = 3; i *1LL* i <= n; i += 2) {
        if(n % i == 0){
            while (n % i == 0) {
                n /= i;
            }
            factors.push_back(i);
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

vector<vector<int>> primFactors, positions, divisables;
int n;
vector<int> a;
void build(){
    primFactors=positions=vector<vector<int>>(n);
    divisables=vector<vector<int>>(N);
    for(int i=0; i<n; i++){
        primFactors[i]=getPrimeFactors(a[i]);
        positions[i].resize(primFactors[i].size());
        for(int j=0; j<primFactors[i].size(); j++){
            positions[i][j]=divisables[primFactors[i][j]].size();
            divisables[primFactors[i][j]].push_back(i);
        }
    }
}

int mem[N];
int solve(int i){
    
    int &ref=mem[i];
    if(~ref)return ref;

    ref=1;
    for(int p=0; p<primFactors[i].size(); p++){
        if(divisables[primFactors[i][p]].size()>positions[i][p]+1){
            ref=max(ref,1+solve(divisables[primFactors[i][p]][positions[i][p]+1]));
        }
    }

    return ref;
}
void Main(const int &T){
    cin>>n;
    a=vector<int>(n);
    cin>>a;
    build();
    memset(mem,-1,sizeof mem);
    int mx=0;
    for(int i=0; i<n; i++){
        mx=max(mx,solve(i));
    }
    cout<<mx<<endl;
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