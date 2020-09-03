#include <iostream>
using namespace std;
int main(void){
    int a, b;
    
    string r = "No";
    cin >> a >> b;
    int turu = a;

    for (turu; turu >= 0; turu--;) {
        if ((turu * 2 + (a - turu) * 4) == b) r = "Yes";
    }
    cout << r;
}