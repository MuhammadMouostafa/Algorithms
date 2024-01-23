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

map<int,set<int>> adj;
map<int,int> cnt,val,chlds;
void reset(){
    adj.clear();
    cnt.clear();
    val.clear();
    chlds.clear();
}
bool is_completly_spacified(int node){
    if(cnt[node]>1)return false;
    for(int ch:adj[node]){
        if(!is_completly_spacified(ch)){
            return false;
        }
        chlds[node]+=chlds[ch];
    }
    
    if(cnt[node]){
        chlds[node]++;
    }else if(chlds[node]){
        return false;
    }

    return true;
}
void set_node(string s){
    int pos=s.find(',');
    
    string vl=s.substr(1,pos-1);
    s=s.substr(pos+1,(int)s.size()-pos-2);
    
    int node=1;
    for(char i:s){
        int nxt=node*2;
        if(i=='R'){
            nxt++;
        }
        adj[node].insert(nxt);
        node=nxt;
    }

    val[node]=stoi(vl);
    cnt[node]++;
}
void print_levels_order(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout << (node==1?"":" ") << val[node];
        for(int ch:adj[node]){
            if(cnt[ch]){
                q.push(ch);
            }
        } 
    }
    cout<<endl;
}
void Main(const int &T){
    reset();
    string s;
    while(cin>>s){
        if(s=="()"){
            if(is_completly_spacified(1)){
                print_levels_order();
            }else{
                cout<<"not complete"<<endl;        
            }
            reset();
        }else{
            set_node(s);
        }
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