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
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (ll i = (n)-1; i >= 0; --i)
#define mes(a) cout << (a) << endl
#define dmes(a, b) cout << (a) << " " << (b) << endl
#define re0 return 0
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define rSort(a) sort(a.rbegin(), a.rend())
#define Rev(a) reverse(a.begin(), a.end())
#define MATHPI acos(-1)
#define itn int
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
struct io
{
    io()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-19;


signed main() {
    ll h, w, m;
    cin >> h >> w >> m;
    map<pair<ll, ll>, bool> mp;
    vll r(h, 0);
    vll c(w, 0);
    
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        mp[{x, y}] = true;
        r[x]++;
        c[y]++;
    }
 
    ll maxR = 0;
    rep(i, h) {
        if (r[i] > maxR) maxR = r[i];
    }
    vll list1;
    rep(i, h) {
        if (r[i] == maxR) list1.pb(i);
    }
 
    ll maxC = 0;
    rep(i, w) {
        if (c[i] > maxC) maxC = c[i];
    }
    vll list2;
    rep(i, w) {
        if (c[i] == maxC) list2.pb(i);
    }
 
    ll ans = maxR + maxC;
    for (auto x : list1) {
        for (auto y : list2) {
            if (mp.count({x, y}) == 0) {
                mes(ans);
                re0;
            }
        }
    }
 
    mes(ans-1);
    
    
}

