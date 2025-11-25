#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    for(int i = 1000; i >= 1; i -= 5) {
        for(int k = i, cnt = 0; cnt < 5; k --, cnt++) {
            if(cnt) cout << " ";
            cout << k;
        }
        cout << "\n";
    }
}