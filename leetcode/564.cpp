/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-23
 * Task: 564 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        bool all9s = true;
        for(char c: n) if(c != '9') all9s = false;
        if(all9s) 
            return stoll(n) + 2;

        int len = (n.length() + 1) / 2;
        while(true) {
            string f1 = n.substr(0, len);
            string f2 = n.substr(0, len);
            if(n.length() & 1) f2.pop_back();
            reverse(f2.begin(), f2.end());
            f1 += f2;
            if(
        
    }
};

