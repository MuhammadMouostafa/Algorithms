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
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

struct edge
{
    int to, len;
    vector<int> parcels;
    edge(int to, int len, vector<int> parcels):to(to),len(len),parcels(parcels){}
    bool operator <(const edge &e)const{
        return len>e.len;
    }
};

int n;
vector<vector<int>> adj;

void floyed(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}
int dijkstra(const int &src,const int &m, const vector<int> &parcels, const vector<pii> &srcdest){
    map<pair<int,vector<int>>,int> dis;
    dis[{src,parcels}]=0;
    priority_queue<edge> q;
    q.push(edge(src,0,parcels));
    while(!q.empty()){
        const edge cur=q.top();
        q.pop();
        if(cur.len>dis[{cur.to,cur.parcels}]){
            continue;
        }
        for(int e=0; e<n; e++){
            if(dis.find({e,cur.parcels})==dis.end()||
                dis[{e,cur.parcels}]>cur.len+adj[cur.to][e]){
                dis[{e,cur.parcels}]=cur.len+adj[cur.to][e];
                q.push(edge(e,dis[{e,cur.parcels}],cur.parcels));
            }
        }
        for(int i=0; i<m; i++){
            int u=srcdest[i].first;
            int v=srcdest[i].second;
            if(u!=cur.to||!cur.parcels[i])continue;
            auto new_parcels = cur.parcels;
            new_parcels[i]--;

            if(dis.find({v,new_parcels})==dis.end()||
                dis[{v,new_parcels}]>cur.len+adj[cur.to][v]){
                dis[{v,new_parcels}]=cur.len+adj[cur.to][v];
                q.push(edge(v,dis[{v,new_parcels}],new_parcels));
            }
        }
    }
    return dis[{src,vector<int>(m)}];
}
void Main(const int &T){
    int m,src;
    cin>>n>>m>>src;
    src--;

    adj=vector<vector<int>>(n,vector<int>(n,1e9));
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u][v]=adj[v][u]=min(adj[u][v],w);
    }
    floyed();
    cin>>m;
    vector<int> parcels(m);
    vector<pii> srcdest(m);
    for(int i=0; i<m; i++){
        cin>>srcdest[i].first>>srcdest[i].second>>parcels[i];
        srcdest[i].first--;
        srcdest[i].second--;
    } 
    cout<<dijkstra(src,m,parcels,srcdest)<<endl;
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