#include <bits/stdc++.h>
using namespace std;

template <class T> inline void input(T &x) {
    register char c = getchar();
    x = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
        ;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    for (; c > 47 && c < 58; c = getchar()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}
struct node {
    node *left, *right;
    int sz;
    node() {}
    node(int b, int e) : left(nullptr), right(nullptr) { sz = e - b + 1; }
};
void update(node *n, int b, int e, int k) {
    if (b == e) {
        n->sz = 0;
        return;
    }
    int mid = (b + e) / 2;
    if (!n->left) n->left = new node(b, mid);
    if (!n->right) n->right = new node(mid + 1, e);
    if (n->left->sz >= k) update(n->left, b, mid, k);
    else
        update(n->right, mid + 1, e, k - n->left->sz);
    n->sz = n->left->sz + n->right->sz;
}

int query(node *n, int b, int e, int k) {
    if (b == e) { return b; }
    int mid = (b + e) / 2;
    if (!n->left) n->left = new node(b, mid);
    if (!n->right) n->right = new node(mid + 1, e);

    if (n->left->sz >= k) return query(n->left, b, mid, k);
    else
        return query(n->right, mid + 1, e, k - n->left->sz);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    node *root = new node(1, n);
    while (q--) {
        char c;
        int r;
        scanf(" %c %d", &c, &r);
        if (c == 'L') {
            printf("%d\n", query(root, 1, n, r));
        } else
            update(root, 1, n, r);
    }
}
