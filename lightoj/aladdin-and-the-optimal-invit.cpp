#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int Find(vector<pair<ll, ll>> &vec){
    ll righttot = 0, res = 0, rightsum = 0;
    for(int i = 1; i < vec.size(); i ++){
        rightsum += vec[i].second;
        righttot += (vec[i].first - vec[0].first) * vec[i].second;
    }
    ll leftsum = 0, lefttot = 0, cur = righttot;
    for(int i = 1; i < vec.size(); i ++){
        ll dist = vec[i].first - vec[i - 1].first;
        leftsum += vec[i - 1].second;
        lefttot += dist * leftsum;
        righttot -= dist * rightsum;
        rightsum -= vec[i].second;
        ll curr = lefttot + righttot;
        if (curr < cur){
            cur = curr;
            res = i;
        }
    }

    return vec[res].first;
        
}
int main(){
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int n, m , q;
        cin >> n >> m >> q;
        vector<pair<ll, ll>> xs, ys;
        for (int i = 0; i < q; i ++){
            ll x, y, z;
            cin >> x >> y >> z;
            xs.push_back({x, z});
            ys.push_back({y, z});
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        printf("Case %d: %d %d\n", cs, Find(xs), Find(ys));
    }
}