#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct item {
    int c, q;
    bool operator<(const item &rhs) const {
        if (q == rhs.q) return c < rhs.c;
        return q > rhs.q;
    }
};

struct node {
    node *left, *right;
    unsigned int pri;
    int val, lazyVal;
    int sum, lazySum;
    int id;
};
unsigned int genPri() {
    unsigned int x = rand();
    unsigned int y = rand();
    return (x << 16) | y;
}
node *reassign(node *n, node *l, node *r, int pri, int val, int sum, int id) {
    n->left = l, n->right = r;
    n->pri = pri;
    n->val = val, n->lazyVal = 0;
    n->sum = sum, n->lazySum = 0;
    n->id = id;
    return n;
}

node *reassign(node *n, node *l, node *r) {
    return reassign(n, l, r, n->pri, n->val, n->sum, n->id);
}

void apply(node *n, int lazyVal, int lazySum) {
    n->val += lazyVal;
    n->lazyVal += lazyVal;
    n->sum += lazySum;
    n->lazySum += lazySum;
}
void down(node *n) {
    if (n->left) apply(n->left, n->lazyVal, n->lazySum);
    if (n->right) apply(n->right, n->lazyVal, n->lazySum);
    n->lazyVal = 0;
    n->lazySum = 0;
}
node *getLeft(node *n) {
    while (n->left) down(n), n = n->left;
    return n;
}

node *getRight(node *n) {
    while (n->right) down(n), n = n->right;
    return n;
}

// {<, >=}
pair<node *, node *> split(node *n, int k) {
    if (!n) return {nullptr, nullptr};
    down(n);
    node *l, *r;
    if (n->val < k) {
        tie(l, r) = split(n->right, k);
        reassign(n, n->left, l);
        return {n, r};
    }
    tie(l, r) = split(n->left, k);
    reassign(n, r, n->right);
    return {l, n};
}

node *merge(node *l, node *r) {
    if (!l || !r) return l ? l : r;
    down(l);
    down(r);
    if (l->pri < r->pri) return reassign(l, l->left, merge(l->right, r));
    return reassign(r, merge(l, r->left), r->right);
}

node *ins(node *root, node *n) {
    node *l, *r;
    tie(l, r) = split(root, n->val);
    return merge(l, merge(n, r));
}

int ans[N];
void traverse(node *root) {
    if (!root) return;
    ans[root->id] = root->sum;
    down(root);
    traverse(root->left);
    traverse(root->right);
}

int main() {
    int n, k;
    scanf("%d", &n);
    item items[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &items[i].c, &items[i].q);
    sort(items, items + n);

    node *root = nullptr;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        node *cur = reassign(new node(), nullptr, nullptr, genPri(), x, 0, i);
        if (!root) root = cur;
        else
            root = ins(root, cur);
    }

    for (auto item : items) {
        node *l, *r;
        tie(l, r) = split(root, item.c);
        if (!r) continue;
        apply(r, -item.c, 1);
        if (!l) {
            root = r;
            continue;
        }

        node *rl = getLeft(r), *lr = getRight(l);
        while (rl->val < lr->val) {
            node *tl, *tr;
            tie(tl, tr) = split(r, rl->val + 1);
            l = ins(l, tl);
            r = tr;
            if (!l || !r) break;
            rl = getLeft(r);
            lr = getRight(l);
        }
        root = merge(l, r);
    }
    traverse(root);
    for (int i = 0; i < k; i++) printf("%d ", ans[i]);
    return 0;
}
