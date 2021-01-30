#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
typedef vector<vector<bool> > vvb;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rrep(i, n) for (int i = 1; i <= int(n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = int(n)-1; i >= 0; --i)

#define MES(a) MES2 a
#define MES2(a0,a1,a2,a3,a4,x,...) x
#define mes_1(x1) cout<<x1<<endl
#define mes_2(x1,x2) cout<<x1<<" "<<x2<<endl
#define mes_3(x1,x2,x3) cout<<x1<<" "<<x2<<" "<<x3<<endl
#define mes_4(x1,x2,x3,x4) cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl
#define mes_5(x1,x2,x3,x4,x5) cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<endl
#define mes(...) CHOOSE((__VA_ARGS__,mes_5,mes_4,mes_3,mes_2,mes_1,~))(__VA_ARGS__)

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)

#define ynmes(a) (a) ? mes("Yes") : mes("No")
#define YNmes(a) (a) ? mes("YES") : mes("NO")
#define re0 return 0
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define rSort(a) sort(a.rbegin(), a.rend())
#define Rev(a) reverse(a.begin(), a.end())
#define MATHPI acos(-1)
#define itn int;
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
struct io { io() { ios::sync_with_stdio(false); cin.tie(0); } };
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

ll fact_mod(ll n, ll mod) {
    ll f = 1; for (ll i = 2; i <= n; i++) f = f * (i % mod) % mod;
    return f;
}

ll modpow(ll x, ll n, ll mod) {
    if(n == 0) return 1;
    ll res = modpow((x * x) % mod, n / 2 , mod);
    if(n & 1) res = (res * x) % mod;
    return res;
}

ll modncr(ll n, ll r, ll mod) {
    if(r > n-r) r = n-r;
    if(r == 0) return 1;
    ll a = 1;
    rep(i, r) a = a * ((n-i) % mod) % mod;
    ll b = modpow(fact_mod(r, mod), mod-2, mod);
    return (a % mod) * (b % mod) % mod;
}



// Binary Index Treeは長さnの数列に対して
// 1. 区間[a,b)にxを加算する
// 2. 区間[a,b)の総和を求める
// という操作をO(log(n))で処理できる
 
// 区間加算にも対応したBinary Index Tree(1-indexで使うことに気をつける)
template <class Abel> struct BIT {
 
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;
    
    BIT(ll n) { 
        init(n);
    }
 
    void init(ll n) { 
        for(ll iter = 0; iter < 2; ++iter) {
            dat[iter].assign(n+1, UNITY_SUM); 
        }
    }
    
    inline void sub_add(ll p, ll a, Abel x) {
        for(ll i = a; i < (ll)dat[p].size(); i += i & -i) {
            dat[p][i] = dat[p][i] + x;
        }
    }
    // 区間[a,b)にxを加算する(a,bは1-index)
    inline void add(ll a, ll b, Abel x) {
        sub_add(0, a, x * -(a - 1)); 
        sub_add(1, a, x);
        sub_add(0, b, x * (b - 1));
        sub_add(1, b, x * (-1));
    }
    
    inline Abel sub_sum(ll p, ll a) {
        Abel res = UNITY_SUM;
        for(ll i = a; i > 0; i -= i & -i) {
            res = res + dat[p][i];
        } 
        return res;
    }
    // 区間[a,b)の総和を計算する(a, bは1-index)
    inline Abel getsum(ll a, ll b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
};
vector<ll> CoordinateCompression(vector<ll> &a) {  // aを0-indexで座標圧縮
    ll n = a.size();
    vll v = a;
    sort(all(v));
    v.erase(unique(all(v)), v.end());  // vの要素から重複を除く
    vll b(n);  // aを0-indexで座標圧縮したvector
    rep(i, n) {
        b[i] = lower_bound(all(v), a[i]) - v.begin();
    }
    return b;
}
 
int main() {
    ll n;
    cin >> n;
    
    vll a(n);
    map <ll, ll> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    // aを1-indexで座標圧縮
    vll A = CoordinateCompression(a);
    rep(i, n) {
        A[i]++;
    }
    
    BIT<ll> biTree(n+10);
    ll r = 0;  // aの転倒数(i < j かつ a[i] > a[j] となる(i,j)の個数)
    rep(i, n) {
        r += i - biTree.getsum(1, A[i] + 1);
        biTree.add(A[i], A[i] + 1, 1);
    }
 //転倒数ここまで
    
    for(ll i : a){
        mes(r);
        r += n - 1 - i * 2;
    }

}