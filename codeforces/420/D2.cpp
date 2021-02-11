#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    OS;

int p[1000005];
int pos[1000005];
int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	OS ss;
	for(int i = 1; i <= n; i ++) ss.insert(make_pair(i,i)), p[i]  = -1, pos[i] = -1;

	int front = -1;
	for(int i = 0; i < m; i ++) {
		int x,y;
		scanf("%d %d", &x,&y);
		int rak, org;
		tie(rak, org) = *ss.find_by_order(y-1);
		if(pos[x] != -1 && pos[x] != org) {
			cout << -1 << endl;
			return 0;
		}
		if(p[org] != -1 && p[org] != x) {
			cout << -1 << endl;
			return 0;
		}
		p[org] = x;
		pos[x] = org;
		
		ss.erase(make_pair(rak,org));
		ss.insert({front--, org });
	}
	for(int i = 1, j = 1; i <= n; i ++) {
		if(p[i] == -1) {
			while(pos[j] != -1) j ++;
			p[i] = j;
			j ++;
		}
	}
	for(int i = 1; i <= n; i ++) printf("%d ", p[i]);
}
