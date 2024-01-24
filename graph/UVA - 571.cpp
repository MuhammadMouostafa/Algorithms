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



int A,B,W;
bool solved=true;
string moves[] = {"fill A","fill B","empty A","empty B","pour A B","pour B A"};
void update_distance(const int &i, const int &j, const int &x, const int &y,
    queue<pii> &q, vector<vector<int>> &d, vector<vector<pii>> &prev, vector<vector<int>> &operations, int operation)
{
    if(d[x][y]>d[i][j]+1){
        d[x][y]=d[i][j]+1;
        operations[x][y]=operation;
        prev[x][y]={i,j};
        q.push({x,y});
        if(y==W){
            solved=true;
        }
    }
}
void Main(const int &T){
    int n=1001;
    while(cin>>A){
        cin>>B>>W;
        vector<vector<int>> d(n,vector<int>(n,1e9));
        vector<vector<pii>> prev(n,vector<pii>(n));
        vector<vector<int>> operations(n,vector<int>(n,-1));
        d[0][0]=0;
        queue<pii> q;
        q.push({0,0});
        solved=false;
        while(!q.empty()&&!solved){
            int i=q.front().first,j=q.front().second;
            q.pop();

            if(i!=A)update_distance(i,j,A,j,q,d,prev,operations,0);
            if(j!=B)update_distance(i,j,i,B,q,d,prev,operations,1);
            if(i!=0)update_distance(i,j,0,j,q,d,prev,operations,2);
            if(j!=0)update_distance(i,j,i,0,q,d,prev,operations,3);

            if(i!=0&&j!=B){
                int x=i,y=j;
                int mn=min(B-y,x);
                x-=mn;
                y+=mn;
                update_distance(i,j,x,y,q,d,prev,operations,4);
            }

            
            if(i!=A&&j!=0){
                int x=i,y=j;
                int mn=min(A-x,y);
                x+=mn;
                y-=mn;
                update_distance(i,j,x,y,q,d,prev,operations,5);
            }
            
        }

        vector<string> path;

        int x=0,y=W;
        for(int i=0; i<=A; i++){
            if(d[i][W]!=1e9){
                x=i;
                break;
            }
        }
        while(x||y){
            path.push_back(moves[operations[x][y]]);
            pii prv=prev[x][y];
            x=prv.first;
            y=prv.second;
        }

        reverse(path.begin(),path.end());
        for(string s:path){
            cout<<s<<endl;
        }
        cout<<"success"<<endl;
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