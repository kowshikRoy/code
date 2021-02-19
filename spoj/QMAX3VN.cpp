#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

struct node {
    node *left, *right;
    unsigned int pri;
    int sz;
    int height;
    int val;
};
unsigned int genPri() {
    unsigned int x = rand(), y = rand();
    return x << 16 | y;
}
node *reassign(node *n, node *l, node *r, unsigned int pri, int sz, int height,
               int val) {
    n->left = l;
    n->right = r;
    n->pri = pri;
    n->sz = sz;
    n->height = height;
    n->val = val;
    return n;
}

inline int sz(node *n) { return n ? n->sz : 0; }

node *reassign(node *n, node *l, node *r) {
    return reassign(n, l, r, n->pri, 1 + (l ? l->sz : 0) + (r ? r->sz : 0),
                    n->height,
                    max(n->height, max(l ? l->val : -INF, r ? r->val : -INF)));
}

// {<, >= }
pair<node *, node *> split(node *n, int k, int add = 0) {
    if (!n) return {nullptr, nullptr};
    node *l, *r;
    int curPos = add + sz(n->left) + 1;
    if (curPos < k) {
        tie(l, r) = split(n->right, k, curPos);
        reassign(n, n->left, l);
        return {n, r};
    }
    tie(l, r) = split(n->left, k, add);
    reassign(n, r, n->right);
    return {l, n};
}

node *merge(node *l, node *r) {
    if (!l || !r) return l ? l : r;
    if (l->pri < r->pri) return reassign(l, l->left, merge(l->right, r));
    return reassign(r, merge(l, r->left), r->right);
}

node *ins(node *root, node *n, int k) {
    node *l, *r;
    tie(l, r) = split(root, k);
    return merge(l, merge(n, r));
}

int query(node *root, int x, int y) {
    node *l, *r, *a, *b;
    tie(l, r) = split(root, x);
    tie(a, b) = split(r, y + 1);
    return a->val;
}

void traverse(node *n, int add = 0) {
    if (!n) return;
    int curPos = add + sz(n->left);
    traverse(n->left, add);
    traverse(n->right, curPos + 1);
}

int main() {
    int q;
    scanf("%d", &q);
    node *root = nullptr;
    while (q--) {
        char type;
        int x, y;
        scanf(" %c %d %d", &type, &x, &y);
        if (type == 'A') {
            node *cur =
                reassign(new node(), nullptr, nullptr, genPri(), 1, x, x);
            if (!root) root = cur;
            else
                root = ins(root, cur, y);
            printf("------------\n");
            traverse(root);
        } else {
            //		cout << query(root, x, y);
        }
    }
}
