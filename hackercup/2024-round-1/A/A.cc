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


int main(){
    int t,cs= 0,N;
    cin>>t;
    while(t--){
        cin >> N;
        double low = -1e9, high = 1e9;
        int a,b;
        for(int i = 1; i <= N; i ++) {
            cin >> a >> b;
            if(b != 0) {
                low = max(low, i * 1.0 / b);
            }
            if (a != 0) {
                high = min(high, i * 1.0 / a);
            }
            // dbg(low, high);

        }
        if(low <= high + EPS) {
            cout << "Case #" << ++cs << ": " << low << endl;
        }
        else cout << "Case #" << ++cs << ": -1" << endl;
    }

}