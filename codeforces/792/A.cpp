#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>> n;
	int arr[n];
	for(int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int iMax = INT_MAX, ans = 0;
	for(int i = 1; i < n; i ++){
		if(arr[i] - arr[i-1] < iMax) {
			iMax = arr[i] - arr[i-1];
			ans = 1;
		}
		else if(arr[i] - arr[i -1 ] == iMax) ans ++;
	}
	cout << iMax << " " << ans << endl;

	return 0;
}
