/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
 * Task: d 
 */

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+6;
int vis[N];
vector<int> primes;
bool isPrime(int n) {
    if(n < N) return vis[n] == n;
    for(auto &p: primes) {
        if(n % p == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    scanf("%d",&n);
    if(n == 3) {
        printf("1\n3\n");
        return ;
    }
    if(n == 4) {
        printf("2\n2 2\n");
        return;
    }
    n -= 3;
    if(isPrime(n)) {
        printf("2\n%d %d\n", 3, n-3);
        return;
    }
    for(auto p: primes) {
        if(isPrime(n - p)) {
            printf("3\n%d %d %d\n",3,p,n-p);
            return;
        }
    }
}



int main() {
    for(int i = 2; i < N; i ++) {
        if(vis[i] == 0) {
            vis[i] = i;
            primes.push_back(i);
            for(int j = i; j < N; j += i) {
                vis[j] = i;
            }
        }
    }
    solve();
    
} 
