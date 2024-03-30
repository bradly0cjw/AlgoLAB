#include "bits/stdc++.h"

using namespace std;

struct Node {
    bool filled;
    Node *children[4];
    int depth;

    Node() : filled(false) {
        memset(children, 0, sizeof(children));
    }
};

string str;
int counter;

Node *draw(int &p, int depth = 0) {
    Node *node = new Node();
    node->depth = depth;
    char ch = str[p++];
    if (ch == 'p') {
        for (int i = 0; i < 4; i++) {
            node->children[i] = draw(p, depth + 1);
        }
    } else if (ch == 'f') {
        node->filled = true;
        counter++;
    }
    return node;
}

void merge(Node *a, Node *b) {
    if (a->filled || b->filled) {
        a->filled = true;
    } else {
        for (int i = 0; i < 4; i++) {
            if (a->children[i] && b->children[i]) {
                merge(a->children[i], b->children[i]);
            } else if (b->children[i]) {
                a->children[i] = b->children[i];
            }
        }
    }
}

int count(Node *node) {
    if (!node) return 0;
    if (node->filled) {
        return (pow(4, 15 - node->depth)); // 2^30 pixels
    }
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += count(node->children[i]);
    }
    return sum;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        counter = 0;
        Node *root[2];
        for (int j = 0; j < 2; j++) {
            cin >> str;
            int p = 0;
            root[j] = draw(p);
        }
        merge(root[0], root[1]);
        cout << "There are " << count(root[0]) << " black pixels." << endl;
        delete root[0], root[1];
    }
    return 0;
}