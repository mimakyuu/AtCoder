#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int r;
    int x, n;
    int f = 0;
    cin >> x >> n;

    int l, i=0, a[n];

    int u = x + 1;
    int d = x - 1;

    while(cin>>l){
        a[i] = l;
        i++;
    }
    
    std::sort(a, a + n);
    
    for (int i = 0; i < n; i++) {
        if (a[i] == x) f = 1;
        if (a[i] == u) {
            u ++;
        }
        
    }

    std::sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i++) {
        if (a[i] == x) f = 1;
        if (a[i] == d) {
            d --;
        }
        
    }

    r = x;

    if (f == 1) {
        r = d;
        if (abs(u-x) < abs (x-d)) r = u;
    }
    
    cout << r;
}