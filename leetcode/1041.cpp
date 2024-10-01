/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-23
 * Task: 1041 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        unordered_set<array<int,3>> vis;
        vis.insert({0,0,0, -1});
        int X = 0, Y = 0, D = 0;

        auto move = [&]() {
            if(D == 0) Y ++;
            if(D == 1) X --;
            if(D == 2) Y --;
            if(D == 3) X ++;
        };
        for( e) {
            if(x == 'G') {
                move();
                if(

    }
};

