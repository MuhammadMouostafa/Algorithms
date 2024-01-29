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
    freopen("output.out", "w", stdout);
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
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

int n,m;
bool valid(int i , int j){
    return i>=0&&j>=0&&i<n&&j<m;
}
void Main(const int &T){
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    cin>>a;
    vector<vector<int>> dis(n,vector<int>(m,1e9));
    dis[0][0]=a[0][0];
    priority_queue<piii,vector<piii>,greater<piii>> q;
    q.push({a[0][0],{0,0}});
    while(!q.empty()){
        piii cur=q.top();
        q.pop();
        if(dis[cur.second.first][cur.second.second]<cur.first)continue;
        if(cur.second.first==n-1&&cur.second.second==m-1)break;

        for(int k=0; k<4; k++){
            int x=cur.second.first+dx[k];
            int y=cur.second.second+dy[k];
            if(valid(x,y)&&dis[x][y]>dis[cur.second.first][cur.second.second]+a[x][y]){
                dis[x][y]=dis[cur.second.first][cur.second.second]+a[x][y];
                q.push({dis[x][y],{x,y}});
            }
        }
    }
    cout<<dis[n-1][m-1]<<endl;
    
}
int main()
{
    file();
    fast();
    int T = 1;
    cin>>T;
    for(int t=1; t<=T; t++){
        //cout<<"Case "<< t <<": ";
        Main(t);
    }
}