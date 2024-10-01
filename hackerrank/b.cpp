#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bioHazard' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY allergic
 *  3. INTEGER_ARRAY poisonous
 */

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << "]" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
long long bioHazard(int n, vector<int> a, vector<int> p) {
    int m = (int)a.size();
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        g[max(a[i], p[i])].push_back(min(a[i], p[i]));
    }

    long long ans = 0;
    for (int r = 1, l = 0; r <= n; r++) {
        for (auto t : g[r]) { l = max(l, t); }
        ans += (r - l);
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string allergic_count_temp;
    getline(cin, allergic_count_temp);

    int allergic_count = stoi(ltrim(rtrim(allergic_count_temp)));

    vector<int> allergic(allergic_count);

    for (int i = 0; i < allergic_count; i++) {
        string allergic_item_temp;
        getline(cin, allergic_item_temp);

        int allergic_item = stoi(ltrim(rtrim(allergic_item_temp)));

        allergic[i] = allergic_item;
    }

    string poisonous_count_temp;
    getline(cin, poisonous_count_temp);

    int poisonous_count = stoi(ltrim(rtrim(poisonous_count_temp)));

    vector<int> poisonous(poisonous_count);

    for (int i = 0; i < poisonous_count; i++) {
        string poisonous_item_temp;
        getline(cin, poisonous_item_temp);

        int poisonous_item = stoi(ltrim(rtrim(poisonous_item_temp)));

        poisonous[i] = poisonous_item;
    }

    long result = bioHazard(n, allergic, poisonous);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
