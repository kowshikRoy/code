#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

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



/*
 * Complete the 'classifyEdges' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

vector<int> dij(int n, int s, vector<vector<pair<int,int>>>&g) {
    set<pair<int,int>> pq;
    pq.insert({0,s});
    vector<bool>vis(n +1);
    vector<int> dis(n + 1, 1e9);
    dis[s] = 0;
    while(!pq.empty()) {
        auto t = *pq.begin(); pq.erase(pq.begin());
        if(vis[t.second]) continue;

        for(auto nxt: g[t.second]) {
            if(dis[nxt.first] > t.first + nxt.second) {
                dis[nxt.first] = t.first + nxt.second;
                pq.insert({dis[nxt.first], nxt.first});
            }
        }
    }
    return dis;
    
}
vector<string> classifyEdges(int n, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<vector<pair<int,int>>>g(n + 1);
    int m = (int) g_from.size();
    for(int i = 0; i < m; i ++) {
        int u = g_from[i], v = g_to[i], w = g_weight[i];
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    auto f1 = dij(n, 1, g);
    auto fn = dij(n, n, g);
    dbg(f1);
    dbg(fn);

    vector<string> ans;
    for(int i = 0; i < m; i ++) {
        int u = g_from[i], v = g_to[i], w = g_weight[i];
        dbg(u,v,w, f1[u], fn[v], f1[n]);
        dbg(f1[u] + w + fn[v]);
        if((f1[u] + w + fn[v] == f1[n]) || (f1[v] + w + fn[u] == f1[n])) {
            ans.push_back("YES");
        }
        else ans.push_back("NO");
    }
    dbg(ans);
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    vector<string> result = classifyEdges(g_nodes, g_from, g_to, g_weight);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

