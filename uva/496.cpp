#include <bits/stdc++.h>
using namespace std;

set<int> parse(string s){
    istringstream iss(s);
    set<int> vec;
    int a;
    while(iss >> a) vec.insert(a);
    return vec;
}
int main(){
    string str;
    while(getline(cin,str)) {
       set<int> A = parse(str);
        getline(cin, str);
        set<int> B = parse(str);

        if(A.size() == B.size()) {
            bool flag = true;
            for(auto x: A) {
                if(B.count(x) == 0) flag = false;
            }
            if(flag) {
                cout << "A equals B" << endl;
                continue;
            }
        }

        else if (A.size() < B.size()) {
            bool flag = true;
            for(auto x: A) {
                if(B.count(x) == 0) flag = false;
            }
            if(flag) {
                cout << "A is a proper subset of B" << endl;
                continue;
            }
        }
        else if(B.size() < A.size()) {
            bool flag = true;
            for(auto x: B) {
                if(A.count(x) == 0) flag = false;
            }
            if(flag) {
                cout << "B is a proper subset of A" << endl;
                continue;
            }
        }

        // disjoint
        bool joint = true;
        for(auto x: A) {
            if(B.count(x)) joint = false;
        }
        if(joint) cout << "A and B are disjoint" << endl;
        else cout << "I'm confused!" << endl;
        

    }

}
        
