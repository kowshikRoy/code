/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-28
 * Task: 588
 */

#include <bits/stdc++.h>

#include "debug.cpp"
using namespace std;

class FileSystem {
   private:
    struct Node {
        map<string, string> file;
        map<string, Node *> dir;
    };

    vector<string> split(string path) {
        vector<string> ret;
        string cur;
        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                ret.push_back(cur);
                cur = "";
            }else cur.push_back(path[i]);
        }
        if(cur.length() > 0) ret.push_back(cur);
        return ret;
    }

   public:
    Node *root;
    FileSystem() { root = new Node(); }

    vector<string> ls(string path) {
        Node *cur = root;
        auto s    = split(path);
        for (auto x : s) {
            if (cur->dir.count(x)) cur = cur->dir[x];
            else
                return {x};
        }
        vector<string> ret;
        for (auto x : cur->file) ret.push_back(x.first);
        for (auto x : cur->dir) ret.push_back(x.first);
        sort(ret.begin(), ret.end());
        return ret;
    }

    void mkdir(string path) {
        auto s    = split(path);
        Node *cur = root;
        for (auto x : s) {
            if (cur->dir.count(x) == 0) cur->dir[x] = new Node();
            cur = cur->dir[x];
        }
    }

    void addContentToFile(string filePath, string content) {
        auto s   = split(filePath);
        auto cur = root;
        for (int i = 0; i + 1 < s.size(); i++) cur = cur->dir[s[i]];
        auto fileName = s.back();
        cur->file[fileName] += content;
    }

    string readContentFromFile(string filePath) {
        auto s   = split(filePath);
        auto cur = root;
        for (int i = 0; i + 1 < s.size(); i++) cur = cur->dir[s[i]];
        auto fileName = s.back();
        return cur->file[fileName];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
int main() {
    FileSystem fileSystem = FileSystem();
    fileSystem.ls("/");  // return []
    fileSystem.mkdir("/a/b/c");
    fileSystem.addContentToFile("/a/b/c/d", "hello");
    fileSystem.ls("/");                          // return ["a"]
    fileSystem.readContentFromFile("/a/b/c/d");  // return "hello"
}
