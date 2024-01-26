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
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;


void Main(const int &T){
    
    int cas=0;
    int n,m,k;
    while(cin>>n>>m>>k&&(n||m||k)){
        cout<<"Villa #"<<++cas<<endl;
        vector<vector<int>> adj(n);
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>> switchs(n);
        while(k--){
            int u,v;
            cin>>u>>v;
            if(u==v)continue;
            u--;
            v--;
            switchs[u].push_back(v);
        }

        vector<vector<int>> dis(n,vector<int>(1<<n,1e9));
        vector<vector<pii>> par(n,vector<pii>(1<<n));
        vector<vector<int>> operation(n,vector<int>(1<<n));
        queue<pii> q;
        q.push({0,1});
        dis[0][1]=0;

        int x=-1,y;
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            if(x==n-1&&y==(1<<(n-1))){
                break;
            }
            for(int sw:switchs[x]){
                if(!(y&(1<<sw))){
                    int yy=y|(1<<sw);
                    if(dis[x][yy]>dis[x][y]+1){
                        dis[x][yy]=dis[x][y]+1;
                        par[x][yy]={x,y};
                        operation[x][yy]=sw+1;
                        q.push({x,yy});
                    }
                }
            }
            for(int sw:switchs[x]){
                if(y&(1<<sw)){
                    int yy=y^(1<<sw);
                    if(dis[x][yy]>dis[x][y]+1){
                        dis[x][yy]=dis[x][y]+1;
                        par[x][yy]={x,y};
                        operation[x][yy]=-(sw+1);
                        q.push({x,yy});
                    }
                }
            }
            for(int ch:adj[x]){
                if(y&(1<<ch)){
                    if(dis[ch][y]>dis[x][y]+1){
                        dis[ch][y]=dis[x][y]+1;
                        par[ch][y]={x,y};
                        q.push({ch,y});
                    }
                }
            }
        }
        

        if(x==n-1&&y==(1<<(n-1))){
            cout<<"The problem can be solved in "<<dis[x][y]<<" steps:"<<endl;
            vector<string> path;
            while(x||y!=1){
                stringstream ss;
                if(operation[x][y]>0){
                    ss <<"- Switch on light in room "<< operation[x][y] <<"."<<endl;
                }else if(operation[x][y]<0){
                    ss <<"- Switch off light in room "<< -operation[x][y] <<"."<<endl;
                }else{
                    ss <<"- Move to room "<< x+1 <<"."<<endl;
                }
                path.push_back(ss.str());
                pii p=par[x][y];
                x=p.first;
                y=p.second;
            }
            reverse(path.begin(),path.end());
            for(string p:path)cout<<p;
        }else{
            cout<<"The problem cannot be solved."<<endl;
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
        // cout<<"Case "<< t <<": ";
        Main(t);
    }
}