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

int n,m;
vector<vector<int>> g;
bool valid(int i, int j){
    return i>0&&j>0&&i<n&&j<m&&g[i][j]==0;
}
int fix_dir_mod(int i){
    return (i%4+4)%4;
}
void Main(const int &T){
    
    while(cin>>n>>m&&(n||m)){
        g=vector<vector<int>>(n,vector<int>(m));
        cin>>g;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(g[i][j]==1){
                    for(int x=0; x<=1; x++){
                        for(int y=0; y<=1; y++){
                            if(valid(i+x,j+y)){
                                g[i+x][j+y]=2;
                            }
                        }
                    }
                }
            }
        }

        int xs,ys,xe,ye;
        cin>>xs>>ys>>xe>>ye;

        string direction;
        cin>>direction;

        vector<vector<vector<int>>> dis(n,vector<vector<int>>(m,vector<int>(4,1e9)));
        queue<vector<int>> q;

        string directions[] ={"north", "east", "south", "west"};
        for(int i=0; i<4; i++){
            if(directions[i]==direction){
                dis[xs][ys][i]=0;
                q.push({xs,ys,i});
            }
        }

        bool path_found=false;

        while(!q.empty()){
            auto cur=q.front();
            if(cur[0]==xe&&cur[1]==ye){
                cout<<dis[xe][ye][cur[2]]<<endl;
                path_found=true;
                break;
            }
            q.pop();

            for(int d=-1; d<=1; d++){
                auto nxt=cur;
                nxt[2]=fix_dir_mod(nxt[2]+d);
                if(dis[nxt[0]][nxt[1]][nxt[2]]>dis[cur[0]][cur[1]][cur[2]]+1){
                    dis[nxt[0]][nxt[1]][nxt[2]]=dis[cur[0]][cur[1]][cur[2]]+1;
                    q.push(nxt);
                }
            }

            for(int step=1; step<=3; step++){
                int x=cur[0]+dx[cur[2]]*step;
                int y=cur[1]+dy[cur[2]]*step;
                bool ok=true;
                for(int i=min(x,cur[0]); i<=max(x,cur[0]); i++){
                    for(int j=min(y,cur[1]); j<=max(y,cur[1]); j++){
                        ok=ok&&valid(i,j);
                    }
                }

                if(ok&&dis[x][y][cur[2]]>dis[cur[0]][cur[1]][cur[2]]+1){
                    dis[x][y][cur[2]]=dis[cur[0]][cur[1]][cur[2]]+1;
                    q.push({x,y,cur[2]});
                }
            }
        }

        if(!path_found)
        cout<<-1<<endl;
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