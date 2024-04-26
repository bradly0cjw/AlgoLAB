//
// Created by LINBEI on 4/26/2024.
//
#include "bits/stdc++.h"

using namespace std;

int matrix[100][100];

void set_num(int r, int c, int v, int x, int y, int x2, int y2) {
    int midx = (x2 - x) / 2;
    int midy = (y2 - y) / 2;
    if (r <= midx && c <= midy) {
        set_num(r, c, v, x, y, midx, midy);
    } else if (r <= midx && c > midy) {
        set_num(r, c, v, x, midy + 1, midx, y2);
    } else if (r > midx && c <= midy) {
        set_num(r, c, v, midx + 1, y, x2, midy);
    } else {
        set_num(r, c, v, midx + 1, midy + 1, x2, y2);
    }
    if (x == x2 && y == y2) {
        matrix[x][y] = v;
    }
}

int get_num(int &r, int &c, int x, int y, int x2, int y2) {
    int midx = (x2 - x) / 2;
    int midy = (y2 - y) / 2;
    if (r <= midx && c <= midy) {
        get_num(r, c, x, y, midx, midy);
    } else if (r <= midx && c > midy) {
        get_num(r, c, x, midy + 1, midx, y2);
    } else if (r > midx && c <= midy) {
        get_num(r, c, midx + 1, y, x2, midy);
    } else {
        get_num(r, c, midx + 1, midy + 1, x2, y2);
    }
    if (x == x2 && y == y2) {
        return matrix[x][y];
    }
}

int main() {
    return 0;
}