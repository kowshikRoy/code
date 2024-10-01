#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    int shortestSubarray(vector<int>& A, int K) {
        long long s = 0;
        int l       = 0;
        bool found  = false;
        int minLen  = INT_MAX;
        for (int i = 0; i < A.size(); i++) {
            s += A[i];
            if (s < 0) {
                l = i + 1;
                s = 0;
                continue;
            }

            while (s >= K) {
                found  = true;
                minLen = min(minLen, i - l + 1);
                s -= A[l];
            }
        }
        return found ? minLen : -1;
    }
};


int main(){

