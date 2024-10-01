/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 621 
 */

#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        for(char c: tasks) {
            cnt[c - 'A'] ++;
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        int occ = 0;
        for(auto c: cnt) if(c == mx) occ ++;
        return max((int)tasks.size(), (n + 1) *  (mx - 1)   + occ);
    }
};


int main() {
    vector<string> t = {"A","A","A","A","A","A","B","C","D","E","F","G" };
    int n = 2;
    vector<char> v;
    for(auto s: t) v.push_back(s[0]);
    cout<<Solution().leastInterval(v, n)<<endl;
}
