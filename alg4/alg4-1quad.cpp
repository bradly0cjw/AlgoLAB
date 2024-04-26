
//
// Created by LINBEI on 4/26/2024.
//
#include <iostream>

struct QuadNode {
    int value;
    QuadNode *topLeft, *topRight, *bottomLeft, *bottomRight;

    QuadNode(int val = 0) : value(val), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr),
                            bottomRight(nullptr) {}
};

class QuadTree {
private:
    QuadNode *root;

public:
    QuadTree() : root(new QuadNode()) {}

    int get(QuadNode *node, int row, int col, int size) {
        if (size == 1) {
            return node->value;
        }

        size /= 2;
        if (row < size) {
            if (col < size) {
                return get(node->topLeft, row, col, size);
            } else {
                return get(node->topRight, row, col - size, size);
            }
        } else {
            if (col < size) {
                return get(node->bottomLeft, row - size, col, size);
            } else {
                return get(node->bottomRight, row - size, col - size, size);
            }
        }
    }

    void set(QuadNode *node, int row, int col, int size, int value) {
        if (size == 1) {
            node->value = value;
            return;
        }

        size /= 2;
        if (row < size) {
            if (col < size) {
                if (node->topLeft == nullptr) {
                    node->topLeft = new QuadNode();
                }
                set(node->topLeft, row, col, size, value);
            } else {
                if (node->topRight == nullptr) {
                    node->topRight = new QuadNode();
                }
                set(node->topRight, row, col - size, size, value);
            }
        } else {
            if (col < size) {
                if (node->bottomLeft == nullptr) {
                    node->bottomLeft = new QuadNode();
                }
                set(node->bottomLeft, row - size, col, size, value);
            } else {
                if (node->bottomRight == nullptr) {
                    node->bottomRight = new QuadNode();
                }
                set(node->bottomRight, row - size, col - size, size, value);
            }
        }
    }

    int get(int row, int col, int size) {
        return get(root, row, col, size);
    }

    void set(int row, int col, int size, int value) {
        set(root, row, col, size, value);
    }
};