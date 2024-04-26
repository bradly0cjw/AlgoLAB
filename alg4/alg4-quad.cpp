//
// Created by LINBEI on 4/26/2024.
//
#include "bits/stdc++.h"

using namespace std;

struct QuadNode {
    int value;
    char s;
    QuadNode *topLeft, *topRight, *bottomLeft, *bottomRight;

    QuadNode(int val = 0) : value(val), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr),
                            bottomRight(nullptr) {}
};

class QuadTree {
private:
    QuadNode *root;

public:
    QuadTree() : root(new QuadNode()) {}

    QuadNode *mergeQuadTrees(QuadNode *q1, QuadNode *q2, QuadNode *q3, QuadNode *q4) {
        // Base case: if any of the nodes are null, return the non-null node or null
        if (!q1) return clone(q2 ? q2 : (q3 ? q3 : q4));
        if (!q2) return clone(q3 ? q3 : q4);
        if (!q3) return clone(q4);
        if (!q4) return clone(q1);

        // Create a new node
        QuadNode *newNode = new QuadNode();

        // Set the value of the new node to the result of merging the values of the input nodes
        newNode->value = max({q1->value, q2->value, q3->value, q4->value});

        // Recursively merge the child nodes
        newNode->topLeft = mergeQuadTrees(q1->topLeft, q2->topLeft, q3->topLeft, q4->topLeft);
        newNode->topRight = mergeQuadTrees(q1->topRight, q2->topRight, q3->topRight, q4->topRight);
        newNode->bottomLeft = mergeQuadTrees(q1->bottomLeft, q2->bottomLeft, q3->bottomLeft, q4->bottomLeft);
        newNode->bottomRight = mergeQuadTrees(q1->bottomRight, q2->bottomRight, q3->bottomRight, q4->bottomRight);

        return newNode;
    }

    QuadNode *clone(QuadNode *node) {
        if (!node) return nullptr;
        QuadNode *newNode = new QuadNode(node->value);
        newNode->topLeft = clone(node->topLeft);
        newNode->topRight = clone(node->topRight);
        newNode->bottomLeft = clone(node->bottomLeft);
        newNode->bottomRight = clone(node->bottomRight);
        return newNode;
    }
};