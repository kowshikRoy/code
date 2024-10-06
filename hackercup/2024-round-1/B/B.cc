#include <iostream>
#include <vector>
using namespace std;


#define EPS 1e-9
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H;
  if (sizeof...(T)) cerr << ", ";
  dbg_out(T...);
}

#define dbg(...)                                                     \
  cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
      dbg_out(__VA_ARGS__)


const int N = 20000000;
// const int N = 1000;
int main(){
    vector<bool>b(N + 7);
    for(long long i = 2; i < N; i ++) {
        for(long long j = 2*i; j < N; j += i ) {
            b[j] = 1;
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i < N; i += 2) if(b[i] == 0) primes.push_back(i);
    // for(int i = 0; i < 100; i ++) cout << " " << primes[i]; cout << endl;

    vector<int> dp(N + 1);
    dp[5] = 2;
    for(int i = 3; i < primes.size(); i ++) {
        if(b[primes[i] - 2] == 0) dp[primes[i]] = 1;
    }
    vector<int>pre(N + 1);
    for(int i = 1; i < N; i ++) pre[i] = pre[i-1] + dp[i];

    int t,cs =0;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << "Case #" << ++cs << ": " << pre[n] << endl;
    }


}