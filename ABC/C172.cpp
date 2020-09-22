#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
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

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define mes(a) cout << (a) << endl
#define dmes(a, b) cout << (a) << " " << (b) << endl
#define re0 return 0
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define rSort(a) sort(a.rbegin(), a.rend())
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

signed main(void)
{    
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll r = 0;
    
    vll as(n+1), bs(m+1);
    as[0] = 0; bs[0] = 0;
    
    
    ll a, b;
    ll amax = 0;
    ll bmax = 0;
    rrep(i, n) {
        cin >> a;
        as[i] = as[i-1] + a;
        if (as[i] <= k) amax++;
    }
    rrep(i, m) {
        cin >> b;
        bs[i] = bs[i-1] + b;
        if (bs[i] <= k) bmax++;
    }
    
    for(ll i = 0; i <= amax; i++) {
        if (as[i] > k) continue;
        for(ll j = bmax; j >= 0; j--) {   
            if (as[i] + bs[j] <= k) {
                r = max(r, i+j);
                bmax = j;
                break;
            }
            
        }
        
    }
    
    mes(r);
    
    
    
    
    
    
}