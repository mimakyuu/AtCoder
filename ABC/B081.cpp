#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int l, i=0, a[n];
    int f = 0;
    int r = 0;
    while(cin>>l){
        a[i] = l;
        i++;
    }
    
    while(f == 0) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                f = 1;
            }
        }
        if (f == 0){
            for (int i = 0; i < n; i++) {
                a[i] /= 2;  
            }
            r++;
        }
    }
    cout << r;
}