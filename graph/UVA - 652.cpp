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

struct puzzle{
    string state;
    int x,y,n=3;
    bool valid(int i, int j){
        return i>=0&&j>=0&&i<n&&j<n;
    }
    bool do_operation(int k){
        int x2=x+dx[k];
        int y2=y+dy[k];
        if(!valid(x2,y2))return false;
        swap(state[x*n+y],state[x2*n+y2]);
        x=x2;
        y=y2;
        return true;
    }
};

map<string,char> operations;
map<string,string> par;
void build(){
    puzzle src;
    src.state="123456789";
    src.x=src.y=2;

    queue<puzzle> q;
    q.push(src);

    operations[src.state]='#';
    string oposite_directions="dlur";

    while(!q.empty()){
        puzzle cur = q.front();
        q.pop();
        
        for(int k=0; k<4; k++){
            puzzle ch=cur;
            if(ch.do_operation(k)&&operations.find(ch.state)==operations.end()){
                operations[ch.state]=oposite_directions[k];
                par[ch.state]=cur.state;
                q.push(ch);
            }
        }
    }
}
void Main(const int &T){
    if(T>1)cout<<endl;
    string curren_puzzel;
    for(int i=0; i<9; i++){
        char c;
        cin>>c;
        if(!isdigit(c))c='9';
        curren_puzzel.push_back(c);
    }
    

    if(operations.find(curren_puzzel)==operations.end()){
        cout<<"unsolvable"<<endl;
        return;
    }

    while(curren_puzzel!="123456789"){
        cout<<operations[curren_puzzel];
        curren_puzzel=par[curren_puzzel];
    }
    cout<<endl;
    
}
int main()
{
    file();
    fast();
    int T = 1;
    cin>>T;
    build();
    for(int t=1; t<=T; t++){
        // cout<<"Case "<< t <<": ";
        Main(t);
    }
}