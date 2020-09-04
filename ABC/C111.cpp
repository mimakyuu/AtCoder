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
    ll n;
    cin >> n;
    
    map <ll, ll> mp0;
    map <ll, ll> mp1;
    
    
    vll v(n);
    rep(i, n) {
        cin >> v[i];
        if (i % 2 == 0) {
            mp0[v[i]] ++;
        } else {
            mp1[v[i]] ++;
        }
    }
    
    ll i01 = 0;
    ll i02 = 0;
    ll i11 = 0;
    ll i12 = 0;
    
    for (auto i : mp0) {
        if (i.second >= mp0[i01]) {
            i02 = i01;
            i01 = i.first;
        } else if (i.second >= mp0[i02]) {
            i02 = i.first;
        }
    }
    
    for (auto i : mp1) {
        if (i.second >= mp1[i11]) {
            i12 = i11;
            i11 = i.first;
        } else if (i.second >= mp1[i12]) {
            i12 = i.first;
        }
    }
    
    
    if (i01 == i11) {
        mes( min (n - mp0[i02] - mp1[i11], n - mp0[i01] - mp1[i12]) );
    } else mes(n - mp0[i01] - mp1[i11]);
    
    
    
    
    
    
    
}