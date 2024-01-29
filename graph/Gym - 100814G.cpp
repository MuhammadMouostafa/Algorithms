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

struct edge
{
    int to;
    ll cost,wisdom;
    edge(int to, ll cost, ll wisdom):to(to),cost(cost),wisdom(wisdom){}
    bool operator <(const edge &e)const{
        return cost>e.cost;
    }
};

int n;
vector<vector<edge>> adj;

ll dijkstra(double wisdom){
    vector<ll> dis(n,1e18);
    dis[0]=0;
    priority_queue<edge> q;
    q.push(edge(0,0,0));
    while(!q.empty()){
        edge cur=q.top();
        q.pop();
        if(cur.cost>dis[cur.to]){
            continue;
        }
        for(edge e:adj[cur.to]){
            if(e.wisdom<=wisdom&&dis[e.to]>cur.cost+e.cost){
                dis[e.to]=cur.cost+e.cost;
                q.push(edge(e.to,dis[e.to],e.wisdom));
            }
        }
    }
    return dis[n-1]; 
}
void Main(const int &T){
    int m,k;
    cin>>n>>m>>k;
    adj=vector<vector<edge>>(n);
    while(m--){
        int u,v;
        ll cost,wisdom;
        cin>>u>>v>>cost>>wisdom;
        u--;
        v--;
        adj[u].push_back(edge(v,cost,wisdom));
        adj[v].push_back(edge(u,cost,wisdom));
    }
    ll lo=0,hi=1e9,ans=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(dijkstra(mid)<k){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    file();
    fast();
    int T = 1;
    cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case #"<< t <<": ";
        Main(t);
    }
}