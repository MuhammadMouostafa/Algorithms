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

string get_child(const std::string& str, const std::string& findStr, const std::string& replaceStr) {
    size_t pos = 0;
    string res = str;
    while ((pos = res.find(findStr, pos)) != std::string::npos) {
        res.replace(pos, findStr.length(), replaceStr);
        pos += replaceStr.length();
    }
    return res;
}
void Main(const int &T){
    int n;
    while(cin>>n&&n){
        vector<vector<string>> paterns(n,vector<string>(2));
        cin>>paterns;

        string src,des;
        cin>>src>>des;

        set<string> vis;
        vis.insert(src);

        queue<string> q;
        q.push(src);

        int dep=0;
        while(!q.empty()){
            
            int sz=q.size();
            while (sz--)
            {
                src=q.front();
                q.pop();
                if(src==des){
                    break;
                }
                for(auto p:paterns){
                    string ch=get_child(src,p[0],p[1]);
                    if(ch.size()<=des.size()&&vis.find(ch)==vis.end()){
                        vis.insert(ch);
                        q.push(ch);
                    }
                }
            }
            if(src==des){
                break;
            }
            
            dep++;
        }

        cout<<(src==des?dep:-1)<<endl;
        
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